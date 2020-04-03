#pragma once

#include <cstdint>
#include <string>

#include "engine/Core.h"

namespace fnd {

  enum class EventType {
    None,
    WindowClosed, WindowResized, WindowFocused, WindowLostFocus, WindowMoved,
    KeyPressed, KeyReleased, KeyTyped,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
  };

  enum EventCategory : uint32_t {
    None = 0,
    Application = BIT(0u),
    Input       = BIT(1u),
    Keyboard    = BIT(2u),
    Mouse       = BIT(3u),
    MouseButton = BIT(4u),
    Window      = BIT(5u)
  };

  #define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return type; }\
                                 virtual EventType getEventType() const override { return getStaticType(); }\
                                 virtual const char* getName() const override { return #type; }

  #define EVENT_CLASS_CATEGORY(category) virtual uint32_t getCategoryFlags() const override { return category; }

  class Event {
  public:
    bool handled = false;

    virtual EventType getEventType() const = 0;
    virtual const char* getName() const = 0;
    virtual uint32_t getCategoryFlags() const = 0;
    virtual std::string toString() const { return getName(); }

    inline bool isInCategory(EventCategory category) {
      return getCategoryFlags() & static_cast<unsigned int>(category);
    }

    inline std::ostream& operator <<(std::ostream& os) const {
      return os << toString();
    }
  };

  class EventDispatcher {
  public:
    explicit EventDispatcher(Event& event) :
      event(event) {};

    template<typename T, typename F>
    bool dispatch(const F& func) {
      if (event.getEventType() == T::getStaticType()) {
        event.handled = func(static_cast<T&>(event));
        return true;
      }
      return false;
    }

  private:
    Event& event;
  };

  inline std::ostream& operator<<(std::ostream& os, const Event& e) {
    return os << e.toString();
  }

}
