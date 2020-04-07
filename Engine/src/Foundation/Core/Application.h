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