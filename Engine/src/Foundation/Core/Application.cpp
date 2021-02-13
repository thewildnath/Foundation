#include "Foundation/fndpch.h"
#include "Application.h"

// TODO: temporary testing
#include <glad/glad.h>

#include "Foundation/Core.h"
#include "Foundation/Core/LayerManager.h"
#include "Foundation/Core/LogManager.h"
#include "Foundation/Core/Window.h"
#include "Foundation/Events/WindowEvents.h"
#include "Foundation/ImGui/ImGuiLayer.h"
#include "Foundation/Input/InputManager.h"
#include "Foundation/Utils/Singleton.h"

namespace fnd {

  template<> Application* Singleton<Application>::s_singleton = nullptr;

  // TODO: temporary testing
  static SharedPtr<VertexArray> createVertexArrayFromData(
      float* vertices, size_t verticesSize,
      uint32_t* indices, size_t indicesCount,
      const BufferLayout& layout) {
    auto vertexArray = VertexArray::create();

    auto vertexBuffer = VertexBuffer::create(vertices, verticesSize);
    vertexBuffer->setLayout(layout);
    vertexArray->addVertexBuffer(vertexBuffer);

    auto indexBuffer = IndexBuffer::create(indices, indicesCount);
    vertexArray->setIndexBuffer(indexBuffer);

    return vertexArray;
  }

  Application::Application() {
    // Initialise log manager
    if (!LogManager::getSingletonPtr()) {
      new LogManager();
    }

    // Create window
    m_window = Window::create();
    m_window->setEventCallback(FND_BIND_EVENT_FN(Application::onEvent));

    // Initialise other systems
    m_logPtr = UniquePtr<LogManager>(LogManager::getSingletonPtr());
    m_inputManagerPtr = makeUnique<InputManager>();
    m_layerManagerPtr = makeUnique<LayerManager>();
    m_renderingManagerPtr = makeUnique<RenderingManager>();

    // Create default ImGui layer
    m_ImGuiLayer = new ImGuiLayer();
    pushOverlay(m_ImGuiLayer);

    m_running = true;

    // testing
    {
      BufferLayout layout = {
        {ShaderDataType::Float3, "a_Position"},
        {ShaderDataType::Float4, "a_Color"}
      };

      float squareVertices[4 * (3 + 4)] = {
        -0.75f, -0.75f, 0.0f, 0.2f, 0.2f, 0.8f, 1.0f,
        -0.75f, 0.75f, 0.0f, 0.3f, 0.3f, 0.5f, 1.0f,
        0.75f, 0.75f, 0.0f, 0.9f, 0.9f, 0.9f, 1.0f,
        0.75f, -0.75f, 0.0f, 0.3f, 0.3f, 0.5f, 1.0f
      };
      uint32_t squareIndices[6] = {0, 1, 2, 0, 2, 3};

      float triangleVertices[3 * (3 + 4)] = {
        -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.2f, 1.0f,
        0.5f, -0.5f, 0.0f, 0.2f, 0.8f, 0.2f, 1.0f,
        0.0f, 0.5f, 0.0f, 0.2f, 0.2f, 0.8f, 1.0f,
      };
      uint32_t triangleIndices[3] = {0, 1, 2};

      m_vertexArrays.push_back(createVertexArrayFromData(
        squareVertices, sizeof(squareVertices),
        squareIndices, sizeof(squareIndices) / sizeof(uint32_t),
        layout));

      m_vertexArrays.push_back(createVertexArrayFromData(
        triangleVertices, sizeof(triangleVertices),
        triangleIndices, sizeof(triangleIndices) / sizeof(uint32_t),
        layout));

      std::string shaderVertexSrc = R"(
        #version 330 core

        layout(location = 0) in vec3 a_Position;
        layout(location = 1) in vec4 a_Color;

        out vec3 v_Position;
        out vec4 v_Color;

        void main() {
          v_Position = a_Position;
          v_Color = a_Color;
          gl_Position = vec4(a_Position, 1.0f);
        }
      )";

      std::string shaderFragmentSrc = R"(
        #version 330 core

        layout(location = 0) out vec4 color;

        in vec3 v_Position;
        in vec4 v_Color;

        void main() {
          // color = vec4(0.8f, 0.2f, 0.2f, 1.0f);
          // color = vec4(v_Position * 0.5f + 0.5f, 1.0f);
          color = v_Color;
        }
      )";

      m_shader = makeUnique<Shader>(shaderVertexSrc, shaderFragmentSrc);
      m_shader->bind();
    }
  }

  void Application::run() {
    while (m_running) {
      // TODO: remove this testing code
      {
        static int frame = 0;
        ++frame;
        if ((frame / 50) % 2) {
          glClearColor(0.14, 0.14, 0.14, 1);
        } else {
          glClearColor(0.15, 0.15, 0.15, 1);
        }
        glClear(GL_COLOR_BUFFER_BIT);

        m_shader->bind();

        for (const auto& vertexArray : m_vertexArrays) {
          vertexArray->bind();
          glDrawElements(GL_TRIANGLES, vertexArray->getIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr);
        }
      }

      // Update layers in order
      for (Layer* layer : *m_layerManagerPtr) {
        layer->onUpdate();
      }

      // Update ImGui
      m_ImGuiLayer->begin();
      for (Layer* layer : *m_layerManagerPtr) {
        layer->onImGui();
      }
      m_ImGuiLayer->end();

      m_window->onUpdate();
    }
  }

  void Application::onEvent(Event& e) {
    // Temporary input test
    if (e.isInCategory(EventCategory::Input)) {
      m_inputManagerPtr->onEvent(e);
      return;
    }

    EventDispatcher dispatcher(e);
    dispatcher.dispatch<WindowCloseEvent>(FND_BIND_EVENT_FN(Application::onWindowClose));

    // Propagate event inversely through layers
    for (auto it = m_layerManagerPtr->rbegin(); it != m_layerManagerPtr->rend() && !e.handled; ++it) {
      (*it)->onEvent(e);
    }
  }

  // LayerManager wrapper
  void Application::pushLayer(fnd::Layer* layer) {
    m_layerManagerPtr->pushLayer(layer);
  }

  void Application::pushOverlay(fnd::Layer* overlay) {
    m_layerManagerPtr->pushOverlay(overlay);
  }

  void Application::popLayer(fnd::Layer* layer) {
    m_layerManagerPtr->popLayer(layer);
  }

  void Application::popOverlay(fnd::Layer* overlay) {
    m_layerManagerPtr->popOverlay(overlay);
  }

  bool Application::onWindowClose(fnd::WindowCloseEvent &e) {
    m_running = false;
    return true;
  }

}
