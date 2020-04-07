#pragma once

#include <GLFW/glfw3.h>

#include "Foundation/fndpch.h"

#include "Foundation/Core/Window.h"

namespace fnd {

  class WindowsWindow : public Window {
  public:
    explicit WindowsWindow(const WindowProps& props);
    ~WindowsWindow() override;

    void onUpdate() override;

    inline uint32_t getWidth() const override { return data.width; }
    inline uint32_t getHeight() const override { return data.height; }

    inline void setEventCallback(const EventCallback& eventCallback) override { data.eventCallback = eventCallback; }

    void setVSync(bool enabled) override;
    inline bool isVSync() const override { return data.vsync; };

    inline void* getNativeWindow() const override { return window; }

  private:
    void init(const WindowProps& props);
    void shutdown();

  private:
    GLFWwindow* window;

    struct WindowData {
      std::string title;
      uint32_t width;
      uint32_t height;
      bool vsync;

      EventCallback eventCallback;
    };

    WindowData data;
  };

}


