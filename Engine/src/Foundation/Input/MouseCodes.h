#pragma once

#include "Foundation/fndpch.h"

namespace fnd {

  typedef enum MouseCode : uint16_t {
    // From glfw3.h
    Button0                = 0,
    Button1                = 1,
    Button2                = 2,
    Button3                = 3,
    Button4                = 4,
    Button5                = 5,
    Button6                = 6,
    Button7                = 7,

    ButtonLast             = Button7,
    ButtonLeft             = Button0,
    ButtonRight            = Button1,
    ButtonMiddle           = Button2
  } Mouse;

  inline std::ostream& operator <<(std::ostream& os, MouseCode mouseCode) {
    os << static_cast<std::underlying_type_t<MouseCode>>(mouseCode);
    return os;
  }
}

#define FND_MOUSE_BUTTON_0      ::fnd::Mouse::Button0
#define FND_MOUSE_BUTTON_1      ::fnd::Mouse::Button1
#define FND_MOUSE_BUTTON_2      ::fnd::Mouse::Button2
#define FND_MOUSE_BUTTON_3      ::fnd::Mouse::Button3
#define FND_MOUSE_BUTTON_4      ::fnd::Mouse::Button4
#define FND_MOUSE_BUTTON_5      ::fnd::Mouse::Button5
#define FND_MOUSE_BUTTON_6      ::fnd::Mouse::Button6
#define FND_MOUSE_BUTTON_7      ::fnd::Mouse::Button7
#define FND_MOUSE_BUTTON_LAST   ::fnd::Mouse::ButtonLast
#define FND_MOUSE_BUTTON_LEFT   ::fnd::Mouse::ButtonLeft
#define FND_MOUSE_BUTTON_RIGHT  ::fnd::Mouse::ButtonRight
#define FND_MOUSE_BUTTON_MIDDLE ::fnd::Mouse::ButtonMiddle