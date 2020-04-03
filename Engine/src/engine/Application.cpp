#include "engine/Application.h"

#include <iostream>

#include "engine/Events/WindowEvents.h"
#include "engine/Log.h"

namespace fnd {

  Application::Application() = default;

  Application::~Application() = default;

  void Application::run() {
    std::cout << "Application is running." << std::endl;

    WindowResizedEvent e(1920, 1080);
    if (e.isInCategory(EventCategory::Window)) {
      FND_E_TRACE(e.toString());
    }
    if (e.isInCategory(EventCategory::Mouse)) {
      FND_E_ERROR(e.toString());
    }
  }

}