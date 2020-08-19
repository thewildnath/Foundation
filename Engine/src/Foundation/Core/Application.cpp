#include "Application.h"

#include <glad/glad.h>

namespace fnd {

  template<> Application* Singleton<Application>::m_singleton = nullptr;

  Application::Application() {

    // TODO: initialise Log first, design Windows and Input

    m_window = Window::create();
    m_window->setEventCallback(FND_BIND_EVENT_FN(Application::onEvent));

    m_running = true;

    // Initialise systems
    if (!LogManager::getSingletonPtr()) {
      new LogManager();
    }
    m_logPtr = UniquePtr<LogManager>(LogManager::getSingletonPtr());
    m_layerManagerPtr = std::make_unique<LayerManager>();
    m_inputManagerPtr = std::make_unique<InputManager>();

    // Create default ImGui layer
    m_ImGuiLayer = new ImGuiLayer();
    pushOverlay(m_ImGuiLayer);
  }

  void Application::run() {
    while (m_running) {
      // TODO: remove this testing code
      {
        static bool faze = false;
        faze = !faze;
        if (faze) {
          glClearColor(1, 0, 1, 1);
        } else {
          glClearColor(0.8, 0.2, 0.8, 1);
        }
        glClear(GL_COLOR_BUFFER_BIT);
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