#pragma once

#include <GLFW/glfw3.h>

#include "Foundation/fndpch.h"
#include "Foundation/Core/Window.h"
#include "Foundation/Rendering/RenderingContext.h"

namespace fnd {

  class WindowsWindow : public Window {
  public:
    explicit WindowsWindow(const WindowProps& props);
    ~WindowsWindow() override;

    void onUpdate() override;

    inline uint32_t getWidth() const override { return m_data.width; }
    inline uint32_t getHeight() const override { return m_data.height; }

    inline void setEventCallback(const EventCallback& eventCallback) override { m_data.eventCallback = eventCallback; }

    void setVSync(int interval) override;
    inline bool isVSync() const override { return m_data.vsync; };

    inline void* getNativeWindow() const override { return m_window; }

  private:
    void init(const WindowProps& props);
    void shutdown();

  private:
    GLFWwindow* m_window{};

    UniquePtr<RenderingContext> m_renderingContext;

    struct WindowData {
      std::string title;
      uint32_t width;
      uint32_t height;
      bool vsync;

      EventCallback eventCallback;
    };

    WindowData m_data;
  };

}


