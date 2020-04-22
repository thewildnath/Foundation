#pragma once

#include "Foundation/fndpch.h"
#include "Foundation/Core/LayerManager.h"
#include "Foundation/Core/Log.h"
#include "Foundation/Core/Window.h"
#include "Foundation/Events/WindowEvents.h"
#include "Foundation/Utils/Singleton.h"

namespace fnd {

  class FND_API Application : public Singleton<Application> {
  public:
    Application();
    virtual ~Application() = default;

    void run();

    void onEvent(Event& e);

    void pushLayer(Layer* layer);
    void pushOverlay(Layer* overlay);
    void popLayer(Layer* layer);
    void popOverlay(Layer* overlay);

  private:
    bool onWindowClose(WindowCloseEvent& e);

    std::unique_ptr<Window> m_window;

    bool m_running;

    // Systems
    UniquePtr<Log> m_logPtr;
    UniquePtr<LayerManager> m_layerManagerPtr;
  };

}