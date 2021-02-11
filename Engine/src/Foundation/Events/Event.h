#pragma once

#include <string>

#include "Foundation/Core.h"
#include "Foundation/Utils/FlagEnums.h"

namespace fnd {

  enum class EventType {
    None,
    WindowClosed, WindowResized, WindowFocused, WindowLostFocus, WindowMoved,
    KeyPressed, KeyReleased, KeyTyped,
    MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
  };

  enum class EventCategory : uint32_t {
    None = 0,
    Application = FND_BIT(0u),
    Input       = FND_BIT(1u),
    Keyboard    = FND_BIT(2u),
    Mouse       = FND_BIT(3u),
    MouseButton = FND_BIT(4u),
    Window      = FND_BIT(5u)
  };
  ENUM_OPERATOR(EventCategory, |)
  ENUM_OPERATOR(EventCategory, &)

  #define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return type; }\
                                 virtual EventType getEventType() const override { return getStaticType(); }\
                                 virtual const char* getName() const override { return #type; }

  #define EVENT_CLASS_CATEGORY(category) virtual EventCategory getCategoryFlags() const override { return category; }

  class FND_API Event {
  public:
    bool handled = false;

    virtual EventType getEventType() const = 0;
    virtual const char* getName() const = 0;
    virtual EventCategory getCategoryFlags() const = 0;
    virtual std::string toString() const { return getName(); }

    inline bool isInCategory(EventCategory category) {
      return (getCategoryFlags() & category) != EventCategory::None;
    }

    inline std::ostream& operator <<(std::ostream& os) const {
      return os << toString();
    }
  };

  class FND_API EventDispatcher {
  public:
    explicit EventDispatcher(Event& event) :
      m_event(event) {};

    template<typename T, typename F>
    bool dispatch(const F& func) {
      if (m_event.getEventType() == T::getStaticType()) {
        m_event.handled = func(static_cast<T&>(m_event));
        return true;
      }
      return false;
    }

  private:
    Event& m_event;
  };

  inline std::ostream& operator<<(std::ostream& os, const Event& e) {
    return os << e.toString();
  }

}
