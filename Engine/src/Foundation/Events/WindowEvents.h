#pragma once

#include <sstream>
#include <string>

#include "Foundation/Events/Event.h"

namespace fnd {

  class WindowCloseEvent : public Event {
  public:
    WindowCloseEvent() = default;

    std::string toString() const override {
      return "WindowCloseEvent";
    }

    EVENT_CLASS_TYPE(EventType::WindowClosed)
    EVENT_CLASS_CATEGORY(EventCategory::Window)
  };

  class WindowResizedEvent: public Event {
  public:
    WindowResizedEvent(uint32_t width, uint32_t height) :
      m_width(width), m_height(height) {};

    inline uint32_t getWidth() const { return m_width; }
    inline uint32_t getHeight() const { return m_height; }

    std::string toString() const override {
      std::stringstream ss;
      ss << "WindowResizedEvent: " << m_width << " " << m_height;
      return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::WindowResized)
    EVENT_CLASS_CATEGORY(EventCategory::Window)

  private:
    uint32_t m_width;
    uint32_t m_height;
  };

}