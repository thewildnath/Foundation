#pragma once

#include "Foundation/fndpch.h"

#include "Foundation/Core/Window.h"
#include "Foundation/Events/WindowEvents.h"
#include "Foundation/Utils/Singleton.h"

namespace fnd {

  class FND_API Application : public Singleton<Application> {
  public:
    Application();
    virtual ~Application();

    void run();

    void onEvent(Event& e);

  private:
    bool onWindowClose(WindowCloseEvent& e);

    std::unique_ptr<Window> m_window;

    bool m_running;
  };

}