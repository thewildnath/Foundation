#pragma once

#include "Foundation/fndpch.h"
#include "Foundation/Core/LayerManager.h"
#include "Foundation/Core/Log.h"
#include "Foundation/Core/Window.h"
#include "Foundation/Events/WindowEvents.h"
#include "Foundation/ImGui/ImGuiLayer.h"
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

    Window* getWindow() { return m_window.get(); };

  private:
    bool onWindowClose(WindowCloseEvent& e);

    UniquePtr<Window> m_window;

    bool m_running;

    // Temporary default ImGui layer. TODO: allow layers to individual ImGui
    ImGuiLayer* m_ImGuiLayer;

    // Systems
    UniquePtr<Log> m_logPtr;
    UniquePtr<LayerManager> m_layerManagerPtr;
  };

}