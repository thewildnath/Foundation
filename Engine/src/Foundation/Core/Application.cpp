#include "Application.h"

namespace fnd {

  Application::Application() {
    window = Window::create();

    running = true;
  }

  Application::~Application() = default;

  void Application::run() {
    while (running) {
      window->onUpdate();
    }
  }

}