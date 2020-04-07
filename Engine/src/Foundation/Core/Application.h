#pragma once

#include "Foundation/fndpch.h"

#include "Foundation/Core/Window.h"

namespace fnd {

  class FND_API Application {
  public:
    Application();
    virtual ~Application() = 0;
    void run();

  private:
    std::unique_ptr<Window> window;

    bool running;
  };

}