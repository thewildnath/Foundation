#pragma once

#include "Core.h"
#include "Log.h"

#ifdef FND_PLATFORM_WINDOWS64

namespace fnd {
  extern Application* createApplication();
}

int main(int argc, char** argv) {
  fnd::Log::init();
  FND_E_INFO("Logger initialised");

  auto app = fnd::createApplication();
  app->run();
  delete app;
}

#endif