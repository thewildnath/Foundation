#pragma once

#include "Core.h"
#include "Log.h"

#ifdef FND_PLATFORM_WINDOWS64

namespace fnd {
  extern Application* createApplication();
}

int main(int argc, char** argv) {
  fnd::Log::init();
  FND_ENGINE_WARN("Logger initialised");
  int a = 5;
  FND_INFO("Hello! Var={0}", a);
  auto app = fnd::createApplication();
  app->run();
  delete app;
}

#endif