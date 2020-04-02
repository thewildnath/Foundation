#pragma once

#include "Core.h"

#include "spdlog/spdlog.h"

#ifdef FND_PLATFORM_WINDOWS64

namespace fnd {
    extern Application* createApplication();
}

int main(int argc, char** argv) {
  spdlog::info("Engine firing up!");
  auto app = fnd::createApplication();
  app->run();
  delete app;
}

#endif