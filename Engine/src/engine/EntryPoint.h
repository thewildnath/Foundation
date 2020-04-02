#pragma once

#include "Core.h"

#ifdef FND_PLATFORM_WINDOWS64

namespace fnd {
    extern Application* createApplication();
}

int main(int argc, char** argv) {
  auto app = fnd::createApplication();
  app->run();
  delete app;
}

#endif