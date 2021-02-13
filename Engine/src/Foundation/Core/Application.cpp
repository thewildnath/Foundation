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
  static GLenum shaderDataTypeToGLBaseType(ShaderDataType type) {
    switch (type) {
      case ShaderDataType::Bool:   return GL_BOOL;
      case ShaderDataType::Int:    return GL_INT;
      case ShaderDataType::Int2:   return GL_INT;
      case ShaderDataType::Int3:   return GL_INT;
      case ShaderDataType::Int4:   return GL_INT;
      case ShaderDataType::Float:  return GL_FLOAT;
      case ShaderDataType::Float2: return GL_FLOAT;
      case ShaderDataType::Float3: return GL_FLOAT;
      case ShaderDataType::Float4: return GL_FLOAT;
      case ShaderDataType::Mat3:   return GL_FLOAT;
      case ShaderDataType::Mat4:   return GL_FLOAT;
    }

    FND_ASSERT(false, "Unknown ShaderDataType");
    return 0;
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
      glGenVertexArrays(1, &m_vertexArray);
      glBindVertexArray(m_vertexArray);

      BufferLayout layout = {
        {ShaderDataType::Float3, "a_Position"},
        {ShaderDataType::Float4, "a_Color"}
      };

      float vertices[3 * (3 + 4)] = {
        -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.2f, 1.0f,
        0.5f, -0.5f, 0.0f, 0.2f, 0.8f, 0.2f, 1.0f,
        0.0f, 0.5f, 0.0f, 0.2f, 0.2f, 0.8f, 1.0f,
      };

      m_vertexBuffer = VertexBuffer::create(vertices, sizeof(vertices));
      m_vertexBuffer->setLayout(layout);
      m_vertexBuffer->bind();

      size_t index = 0;
      for (const auto& element : m_vertexBuffer->getLayout()) {
        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index,
          element.getComponentCount(),
          shaderDataTypeToGLBaseType(element.type),
          element.normalised ? GL_TRUE : GL_FALSE,
          layout.getStride(),
          (const void*)element.offset
        );
        ++index;
      }

      uint32_t indices[3] = {0, 1, 2};
      m_indexBuffer = IndexBuffer::create(indices, sizeof(indices) / sizeof(uint32_t));
      m_indexBuffer->bind();

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

      m_shaderPtr = makeUnique<Shader>(shaderVertexSrc, shaderFragmentSrc);
      m_shaderPtr->bind();
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

        glBindVertexArray(m_vertexArray);
        glDrawElements(GL_TRIANGLES, m_indexBuffer->getCount(), GL_UNSIGNED_INT, nullptr);
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