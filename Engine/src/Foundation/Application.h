#pragma once

#include "Foundation/Core.h"

namespace fnd {

  class FND_API Application {
  public:
    Application();
    virtual ~Application() = 0;
    void run();
  };

}

// TODO: Include spdlog incrementally to check why the dll size increases so much. Also merge into main project