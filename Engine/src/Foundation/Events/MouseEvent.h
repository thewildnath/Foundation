#pragma once

#include "Foundation/fndpch.h"

#include "Foundation/Events/Event.h"
#include "Foundation/Input/MouseCodes.h"

namespace fnd {

  class MouseMovedEvent : public Event {
  public:
    MouseMovedEvent(float x, float y) :
      mouseX(x), mouseY(y) {};

    inline float getX() { return mouseX; }
    inline float getY() { return mouseY; }

    std::string toString() const override {
      std::stringstream ss;
      ss << "MouseMovedEvent: " << mouseX << " " << mouseY;
      return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::MouseMoved)
    EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Mouse)

  private:
    float mouseX;
    float mouseY;
  };

  class MouseScrolledEvent : public Event {
  public:
    MouseScrolledEvent(float x, float y) :
      offsetX(x), offsetY(y) {};

    inline float getX() const { return offsetX; }
    inline float getY() const { return offsetY; }

    std::string toString() const override {
      std::stringstream ss;
      ss << "MouseScrolledEvent: " << offsetX << " " << offsetY;
      return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::MouseScrolled)
    EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Mouse)

  private:
    float offsetX;
    float offsetY;
  };

  class MouseButtonEvent : public Event {
  public:
    inline MouseCode getMouseCode() const { return mouseCode; }

    EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::MouseButton)

  protected:
    explicit MouseButtonEvent(MouseCode mouseCode) :
      mouseCode(mouseCode) {};

    MouseCode mouseCode;
  };

  class MouseButtonPressedEvent : public MouseButtonEvent {
  public:
    MouseButtonPressedEvent(MouseCode mouseCode) :
      MouseButtonEvent(mouseCode) {};

    std::string toString() const override {
      std::stringstream ss;
      ss << "MouseButtonPressedEvent: " << mouseCode;
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
      ss << "MouseButtonReleasedEvent: " << mouseCode;
      return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::MouseButtonReleased)
  };

}