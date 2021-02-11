#pragma once

#include "Foundation/Core.h"
#include "Foundation/Core/LayerManager.h"
#include "Foundation/Core/LogManager.h"
#include "Foundation/Core/Window.h"
#include "Foundation/Events/WindowEvents.h"
#include "Foundation/ImGui/ImGuiLayer.h"
#include "Foundation/Input/InputManager.h"
#include "Foundation/Rendering/RenderingManager.h"
#include "Foundation/Utils/Singleton.h"

#include "Foundation/Rendering/Buffer.h"
#include "Foundation/Rendering/Shader.h"

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

    // Temporary default ImGui layer. TODO: allow layers to individually use ImGui
    ImGuiLayer* m_ImGuiLayer;

    // Systems
    UniquePtr<LogManager> m_logPtr;
    UniquePtr<InputManager> m_inputManagerPtr;
    UniquePtr<LayerManager> m_layerManagerPtr;
    UniquePtr<RenderingManager> m_renderingManagerPtr;

    // temporary
    unsigned int m_vertexArray;
    SharedPtr<VertexBuffer> m_vertexBuffer;
    SharedPtr<IndexBuffer> m_indexBuffer;
    UniquePtr<Shader> m_shaderPtr;
  };

}