#include "engine/Application.h"

#include <iostream>

namespace fnd {

  Application::Application() = default;

  Application::~Application() = default;

  void Application::run() {
    std::cout << "Application is running." << std::endl;
  }

}