#include "Application.h"

namespace fnd {

  Application::Application() {
    window = Window::create();
    window->setEventCallback(FND_BIND_EVENT_FN(Application::onEvent));

    running = true;
  }

  Application::~Application() = default;

  void Application::run() {
    while (running) {
      window->onUpdate();
    }
  }

  void Application::onEvent(Event& e) {
    FND_E_DEBUG(e.toString());

    EventDispatcher dispatcher(e);
    dispatcher.dispatch<WindowCloseEvent>(FND_BIND_EVENT_FN(Application::onWindowClose));
  }

  bool Application::onWindowClose(fnd::WindowCloseEvent &e) {
    running = false;
    return true;
  }

}