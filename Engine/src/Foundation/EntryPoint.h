#pragma once

#include "Foundation/Core.h"

#include "Foundation/Application.h"
#include "Foundation/Log.h"

namespace fnd {
  // To be defined in client
  extern Application* createApplication();
}

#ifdef FND_PLATFORM_WINDOWS64

int main(int argc, char** argv) {
  fnd::Log::init();
  FND_E_INFO("Initialised logger.");

  FND_E_INFO("Creating application.");
  auto app = fnd::createApplication();

  FND_E_INFO("Starting application.");
  app->run();
  FND_E_INFO("Application closed.");

  delete app;

  return 0;
}

#endif