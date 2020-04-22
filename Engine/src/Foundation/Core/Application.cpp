#include "Application.h"

#include <memory>

namespace fnd {

  template<> Application* Singleton<Application>::m_singleton = nullptr;

  Application::Application() {
    m_window = Window::create();
    m_window->setEventCallback(FND_BIND_EVENT_FN(Application::onEvent));

    m_running = true;

    // Initialise systems
    if (!Log::getSingletonPtr()) {
      new Log();
    }
    m_logPtr = UniquePtr<Log>(Log::getSingletonPtr());
    m_layerManagerPtr = std::make_unique<LayerManager>();
  }

  void Application::run() {
    while (m_running) {
      m_window->onUpdate();
    }
  }

  void Application::onEvent(Event& e) {
    FND_DEBUG(e.toString());

    EventDispatcher dispatcher(e);
    dispatcher.dispatch<WindowCloseEvent>(FND_BIND_EVENT_FN(Application::onWindowClose));
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