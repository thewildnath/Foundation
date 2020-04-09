#pragma once

#include "Foundation/fndpch.h"

#include "Foundation/Core/Window.h"
#include "Foundation/Events/WindowEvents.h"

namespace fnd {

  class FND_API Application {
  public:
    Application();
    virtual ~Application() = 0;

    void run();

    void onEvent(Event& e);

  private:
    bool onWindowClose(WindowCloseEvent& e);

    std::unique_ptr<Window> window;

    bool running;
  };

}