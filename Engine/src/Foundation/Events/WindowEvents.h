#pragma once

#include "fndpch.h"

#include "Foundation/Events/Event.h"

namespace fnd {

  class WindowCloseEvent : public Event {
  public:
    WindowCloseEvent() = default;

    EVENT_CLASS_TYPE(EventType::WindowClosed)
    EVENT_CLASS_CATEGORY(EventCategory::Window)
  };

  class WindowResizedEvent: public Event {
  public:
    WindowResizedEvent(uint32_t width, uint32_t height) :
      width(width), height(height) {};

    inline uint32_t getWidth() const { return width; }
    inline uint32_t getHeight() const { return height; }

    std::string toString() const {
      std::stringstream ss;
      ss << "WindowResizedEvent: " << width << " " << height;
      return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::WindowResized)
    EVENT_CLASS_CATEGORY(EventCategory::Window)

  private:
    uint32_t width;
    uint32_t height;
  };

}