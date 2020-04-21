#include "Application.h"

namespace fnd {

  template<> Application* Singleton<Application>::m_singleton = nullptr;

  Application::Application() {
    m_window = Window::create();
    m_window->setEventCallback(FND_BIND_EVENT_FN(Application::onEvent));

    m_running = true;
  }

  Application::~Application() = default;

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

  bool Application::onWindowClose(fnd::WindowCloseEvent &e) {
    m_running = false;
    return true;
  }

}