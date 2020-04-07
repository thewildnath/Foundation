#pragma once

#include "Foundation/fndpch.h"

#include "Foundation/Events/Event.h"
#include "Foundation/Input/KeyCodes.h"

namespace fnd {

  class KeyEvent : public Event {
  public:
    inline KeyCode getKeyCode() const { return keyCode; }

    EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Keyboard)

  protected:
    explicit KeyEvent(KeyCode keyCode) :
      keyCode(keyCode) {};

    KeyCode keyCode;
  };

  class KeyPressedEvent : public KeyEvent {
  public:
    KeyPressedEvent(KeyCode keyCode, int repeatCount) :
      KeyEvent(keyCode), repeatCount(repeatCount) {};

    inline int getRepeatCount() const { return repeatCount; }

    std::string toString() const override {
      std::stringstream ss;
      ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount << " repeats)";
      return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::KeyPressed)

  private:
    int repeatCount;
  };

  class KeyReleasedEvent : public KeyEvent {
  public:
    explicit KeyReleasedEvent(KeyCode keyCode) :
      KeyEvent(keyCode) {};

    std::string toString() const override {
      std::stringstream ss;
      ss << "KeyReleasedEvent: " << keyCode;
      return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::KeyReleased)
  };

  class KeyTypedEvent : public KeyEvent {
  public:
    explicit KeyTypedEvent(KeyCode keyCode) :
      KeyEvent(keyCode) {};

    std::string toString() const override {
      std::stringstream ss;
      ss << "KeyTypedEvent: " << keyCode;
      return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::KeyTyped)
  };
}

