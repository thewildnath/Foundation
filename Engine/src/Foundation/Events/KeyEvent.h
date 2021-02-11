#pragma once

#include <sstream>
#include <string>

#include "Foundation/Events/Event.h"
#include "Foundation/Input/KeyCodes.h"

namespace fnd {

  class KeyEvent : public Event {
  public:
    inline KeyCode getKeyCode() const { return m_keyCode; }

    EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Keyboard)

  protected:
    explicit KeyEvent(KeyCode keyCode) :
      m_keyCode(keyCode) {};

    KeyCode m_keyCode;
  };

  class KeyPressedEvent : public KeyEvent {
  public:
    KeyPressedEvent(KeyCode keyCode, int repeatCount) :
      KeyEvent(keyCode), m_repeatCount(repeatCount) {};

    inline int getRepeatCount() const { return m_repeatCount; }

    std::string toString() const override {
      std::stringstream ss;
      ss << "KeyPressedEvent: " << m_keyCode << " (" << m_repeatCount << " repeats)";
      return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::KeyPressed)

  private:
    int m_repeatCount;
  };

  class KeyReleasedEvent : public KeyEvent {
  public:
    explicit KeyReleasedEvent(KeyCode keyCode) :
      KeyEvent(keyCode) {};

    std::string toString() const override {
      std::stringstream ss;
      ss << "KeyReleasedEvent: " << m_keyCode;
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
      ss << "KeyTypedEvent: " << m_keyCode;
      return ss.str();
    }

    EVENT_CLASS_TYPE(EventType::KeyTyped)
  };
}

