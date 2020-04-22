#pragma once

#include "Foundation/fndpch.h"
#include "Foundation/Events/Event.h"

namespace fnd {

  struct WindowProps {
    std::string title;
    int width;
    int height;

    explicit WindowProps(
      std::string title = "Foundation Engine",
      uint32_t width = 1280,
      uint32_t height = 720) :
      title(title), width(width), height(height) {};
  };

  class FND_API Window {
  public:
    using EventCallback = std::function<void(Event&)>;

    virtual ~Window() = default;

    virtual void onUpdate() = 0;

    virtual uint32_t getWidth() const = 0;
    virtual uint32_t getHeight() const = 0;

    virtual void setEventCallback(const EventCallback& eventCallback) = 0;

    virtual void setVSync(bool enabled) = 0;
    virtual bool isVSync() const = 0;

    virtual void* getNativeWindow() const = 0;

    static std::unique_ptr<Window> create(const WindowProps& props = WindowProps());
  };

}

