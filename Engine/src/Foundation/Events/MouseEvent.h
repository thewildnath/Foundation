#pragma once

#include <sstream>
#include <string>

#include "Foundation/Events/Event.h"
#include "Foundation/Input/MouseCodes.h"

namespace fnd {

  class MouseMovedEvent : public Event {
  public:
    MouseMovedEvent(float x, float y) :
      m_mouseX(x), m_mouseY(y) {};

    inline float getX() { return m_mouseX; }
    inline float getY() { return m_mouseY; }

    std::string toString() const override {
      std::stringstream ss;
      ss << "MouseMovedEvent: " << m_mouseX << " " << m_mouseY;
      return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::MouseMoved)
    EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Mouse)

  private:
    float m_mouseX;
    float m_mouseY;
  };

  class MouseScrolledEvent : public Event {
  public:
    MouseScrolledEvent(float x, float y) :
      m_xOffset(x), m_yOffset(y) {};

    inline float getX() const { return m_xOffset; }
    inline float getY() const { return m_yOffset; }

    std::string toString() const override {
      std::stringstream ss;
      ss << "MouseScrolledEvent: " << m_xOffset << " " << m_yOffset;
      return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::MouseScrolled)
    EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Mouse)

  private:
    float m_xOffset;
    float m_yOffset;
  };

  class MouseButtonEvent : public Event {
  public:
    inline MouseCode getMouseCode() const { return m_mouseCode; }

    EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::MouseButton)

  protected:
    explicit MouseButtonEvent(MouseCode mouseCode) :
      m_mouseCode(mouseCode) {};

    MouseCode m_mouseCode;
  };

  class MouseButtonPressedEvent : public MouseButtonEvent {
  public:
    MouseButtonPressedEvent(MouseCode mouseCode) :
      MouseButtonEvent(mouseCode) {};

    std::string toString() const override {
      std::stringstream ss;
      ss << "MouseButtonPressedEvent: " << m_mouseCode;
      return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::MouseButtonPressed)
  };

  class MouseButtonReleasedEvent : public MouseButtonEvent {
  public:
    MouseButtonReleasedEvent(MouseCode mouseCode) :
      MouseButtonEvent(mouseCode) {};

    std::string toString() const override {
      std::stringstream ss;
      ss << "MouseButtonReleasedEvent: " << m_mouseCode;
      return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::MouseButtonReleased)
  };

}