#pragma once

#include "Foundation/fndpch.h"

namespace fnd {

  typedef enum class KeyCode : uint16_t {
    // From glfw3.h
    Space               = 32,
    Apostrophe          = 39, /* ' */
    Comma               = 44, /* , */
    Minus               = 45, /* - */
    Period              = 46, /* . */
    Slash               = 47, /* / */

    D0                  = 48, /* 0 */
    D1                  = 49, /* 1 */
    D2                  = 50, /* 2 */
    D3                  = 51, /* 3 */
    D4                  = 52, /* 4 */
    D5                  = 53, /* 5 */
    D6                  = 54, /* 6 */
    D7                  = 55, /* 7 */
    D8                  = 56, /* 8 */
    D9                  = 57, /* 9 */

    Semicolon           = 59, /* ; */
    Equal               = 61, /* = */

    A                   = 65,
    B                   = 66,
    C                   = 67,
    D                   = 68,
    E                   = 69,
    F                   = 70,
    G                   = 71,
    H                   = 72,
    I                   = 73,
    J                   = 74,
    K                   = 75,
    L                   = 76,
    M                   = 77,
    N                   = 78,
    O                   = 79,
    P                   = 80,
    Q                   = 81,
    R                   = 82,
    S                   = 83,
    T                   = 84,
    U                   = 85,
    V                   = 86,
    W                   = 87,
    X                   = 88,
    Y                   = 89,
    Z                   = 90,

    LeftBracket         = 91,  /* [ */
    Backslash           = 92,  /* \ */
    RightBracket        = 93,  /* ] */
    GraveAccent         = 96,  /* ` */

    World1              = 161, /* non-US #1 */
    World2              = 162, /* non-US #2 */

    /* Function keys */
      Escape              = 256,
    Enter               = 257,
    Tab                 = 258,
    Backspace           = 259,
    Insert              = 260,
    Delete              = 261,
    Right               = 262,
    Left                = 263,
    Down                = 264,
    Up                  = 265,
    PageUp              = 266,
    PageDown            = 267,
    Home                = 268,
    End                 = 269,
    CapsLock            = 280,
    ScrollLock          = 281,
    NumLock             = 282,
    PrintScreen         = 283,
    Pause               = 284,
    F1                  = 290,
    F2                  = 291,
    F3                  = 292,
    F4                  = 293,
    F5                  = 294,
    F6                  = 295,
    F7                  = 296,
    F8                  = 297,
    F9                  = 298,
    F10                 = 299,
    F11                 = 300,
    F12                 = 301,
    F13                 = 302,
    F14                 = 303,
    F15                 = 304,
    F16                 = 305,
    F17                 = 306,
    F18                 = 307,
    F19                 = 308,
    F20                 = 309,
    F21                 = 310,
    F22                 = 311,
    F23                 = 312,
    F24                 = 313,
    F25                 = 314,

    /* Keypad */
    KP0                 = 320,
    KP1                 = 321,
    KP2                 = 322,
    KP3                 = 323,
    KP4                 = 324,
    KP5                 = 325,
    KP6                 = 326,
    KP7                 = 327,
    KP8                 = 328,
    KP9                 = 329,
    KPDecimal           = 330,
    KPDivide            = 331,
    KPMultiply          = 332,
    KPSubtract          = 333,
    KPAdd               = 334,
    KPEnter             = 335,
    KPEqual             = 336,

    LeftShift           = 340,
    LeftControl         = 341,
    LeftAlt             = 342,
    LeftSuper           = 343,
    RightShift          = 344,
    RightControl        = 345,
    RightAlt            = 346,
    RightSuper          = 347,
    Menu                = 348,

    ENUM_SIZE
  } Key;

  const size_t KEY_CODE_SIZE = static_cast<std::underlying_type_t<KeyCode>>(KeyCode::ENUM_SIZE);

  inline std::ostream& operator <<(std::ostream& os, KeyCode keyCode) {
    os << static_cast<std::underlying_type_t<KeyCode>>(keyCode);
    return os;
  }

}

// From glfw3.h
#define FND_KEY_SPACE           ::fnd::Key::Space
#define FND_KEY_APOSTROPHE      ::fnd::Key::Apostrophe    /* ' */
#define FND_KEY_COMMA           ::fnd::Key::Comma         /* , */
#define FND_KEY_MINUS           ::fnd::Key::Minus         /* - */
#define FND_KEY_PERIOD          ::fnd::Key::Period        /* . */
#define FND_KEY_SLASH           ::fnd::Key::Slash         /* / */
#define FND_KEY_0               ::fnd::Key::D0
#define FND_KEY_1               ::fnd::Key::D1
#define FND_KEY_2               ::fnd::Key::D2
#define FND_KEY_3               ::fnd::Key::D3
#define FND_KEY_4               ::fnd::Key::D4
#define FND_KEY_5               ::fnd::Key::D5
#define FND_KEY_6               ::fnd::Key::D6
#define FND_KEY_7               ::fnd::Key::D7
#define FND_KEY_8               ::fnd::Key::D8
#define FND_KEY_9               ::fnd::Key::D9
#define FND_KEY_SEMICOLON       ::fnd::Key::Semicolon     /* ; */
#define FND_KEY_EQUAL           ::fnd::Key::Equal         /* = */
#define FND_KEY_A               ::fnd::Key::A
#define FND_KEY_B               ::fnd::Key::B
#define FND_KEY_C               ::fnd::Key::C
#define FND_KEY_D               ::fnd::Key::D
#define FND_KEY_E               ::fnd::Key::E
#define FND_KEY_F               ::fnd::Key::F
#define FND_KEY_G               ::fnd::Key::G
#define FND_KEY_H               ::fnd::Key::H
#define FND_KEY_I               ::fnd::Key::I
#define FND_KEY_J               ::fnd::Key::J
#define FND_KEY_K               ::fnd::Key::K
#define FND_KEY_L               ::fnd::Key::L
#define FND_KEY_M               ::fnd::Key::M
#define FND_KEY_N               ::fnd::Key::N
#define FND_KEY_O               ::fnd::Key::O
#define FND_KEY_P               ::fnd::Key::P
#define FND_KEY_Q               ::fnd::Key::Q
#define FND_KEY_R               ::fnd::Key::R
#define FND_KEY_S               ::fnd::Key::S
#define FND_KEY_T               ::fnd::Key::T
#define FND_KEY_U               ::fnd::Key::U
#define FND_KEY_V               ::fnd::Key::V
#define FND_KEY_W               ::fnd::Key::W
#define FND_KEY_X               ::fnd::Key::X
#define FND_KEY_Y               ::fnd::Key::Y
#define FND_KEY_Z               ::fnd::Key::Z
#define FND_KEY_LEFT_BRACKET    ::fnd::Key::LeftBracket   /* [ */
#define FND_KEY_BACKSLASH       ::fnd::Key::Backslash     /* \ */
#define FND_KEY_RIGHT_BRACKET   ::fnd::Key::RightBracket  /* ] */
#define FND_KEY_GRAVE_ACCENT    ::fnd::Key::GraveAccent   /* ` */
#define FND_KEY_WORLD_1         ::fnd::Key::World1        /* non-US #1 */
#define FND_KEY_WORLD_2         ::fnd::Key::World2        /* non-US #2 */

/* Function keys */
#define FND_KEY_ESCAPE          ::fnd::Key::Escape
#define FND_KEY_ENTER           ::fnd::Key::Enter
#define FND_KEY_TAB             ::fnd::Key::Tab
#define FND_KEY_BACKSPACE       ::fnd::Key::Backspace
#define FND_KEY_INSERT          ::fnd::Key::Insert
#define FND_KEY_DELETE          ::fnd::Key::Delete
#define FND_KEY_RIGHT           ::fnd::Key::Right
#define FND_KEY_LEFT            ::fnd::Key::Left
#define FND_KEY_DOWN            ::fnd::Key::Down
#define FND_KEY_UP              ::fnd::Key::Up
#define FND_KEY_PAGE_UP         ::fnd::Key::PageUp
#define FND_KEY_PAGE_DOWN       ::fnd::Key::PageDown
#define FND_KEY_HOME            ::fnd::Key::Home
#define FND_KEY_END             ::fnd::Key::End
#define FND_KEY_CAPS_LOCK       ::fnd::Key::CapsLock
#define FND_KEY_SCROLL_LOCK     ::fnd::Key::ScrollLock
#define FND_KEY_NUM_LOCK        ::fnd::Key::NumLock
#define FND_KEY_PRINT_SCREEN    ::fnd::Key::PrintScreen
#define FND_KEY_PAUSE           ::fnd::Key::Pause
#define FND_KEY_F1              ::fnd::Key::F1
#define FND_KEY_F2              ::fnd::Key::F2
#define FND_KEY_F3              ::fnd::Key::F3
#define FND_KEY_F4              ::fnd::Key::F4
#define FND_KEY_F5              ::fnd::Key::F5
#define FND_KEY_F6              ::fnd::Key::F6
#define FND_KEY_F7              ::fnd::Key::F7
#define FND_KEY_F8              ::fnd::Key::F8
#define FND_KEY_F9              ::fnd::Key::F9
#define FND_KEY_F10             ::fnd::Key::F10
#define FND_KEY_F11             ::fnd::Key::F11
#define FND_KEY_F12             ::fnd::Key::F12
#define FND_KEY_F13             ::fnd::Key::F13
#define FND_KEY_F14             ::fnd::Key::F14
#define FND_KEY_F15             ::fnd::Key::F15
#define FND_KEY_F16             ::fnd::Key::F16
#define FND_KEY_F17             ::fnd::Key::F17
#define FND_KEY_F18             ::fnd::Key::F18
#define FND_KEY_F19             ::fnd::Key::F19
#define FND_KEY_F20             ::fnd::Key::F20
#define FND_KEY_F21             ::fnd::Key::F21
#define FND_KEY_F22             ::fnd::Key::F22
#define FND_KEY_F23             ::fnd::Key::F23
#define FND_KEY_F24             ::fnd::Key::F24
#define FND_KEY_F25             ::fnd::Key::F25

/* Keypad */
#define FND_KEY_KP_0            ::fnd::Key::KP0
#define FND_KEY_KP_1            ::fnd::Key::KP1
#define FND_KEY_KP_2            ::fnd::Key::KP2
#define FND_KEY_KP_3            ::fnd::Key::KP3
#define FND_KEY_KP_4            ::fnd::Key::KP4
#define FND_KEY_KP_5            ::fnd::Key::KP5
#define FND_KEY_KP_6            ::fnd::Key::KP6
#define FND_KEY_KP_7            ::fnd::Key::KP7
#define FND_KEY_KP_8            ::fnd::Key::KP8
#define FND_KEY_KP_9            ::fnd::Key::KP9
#define FND_KEY_KP_DECIMAL      ::fnd::Key::KPDecimal
#define FND_KEY_KP_DIVIDE       ::fnd::Key::KPDivide
#define FND_KEY_KP_MULTIPLY     ::fnd::Key::KPMultiply
#define FND_KEY_KP_SUBTRACT     ::fnd::Key::KPSubtract
#define FND_KEY_KP_ADD          ::fnd::Key::KPAdd
#define FND_KEY_KP_ENTER        ::fnd::Key::KPEnter
#define FND_KEY_KP_EQUAL        ::fnd::Key::KPEqual

#define FND_KEY_LEFT_SHIFT      ::fnd::Key::LeftShift
#define FND_KEY_LEFT_CONTROL    ::fnd::Key::LeftControl
#define FND_KEY_LEFT_ALT        ::fnd::Key::LeftAlt
#define FND_KEY_LEFT_SUPER      ::fnd::Key::LeftSuper
#define FND_KEY_RIGHT_SHIFT     ::fnd::Key::RightShift
#define FND_KEY_RIGHT_CONTROL   ::fnd::Key::RightControl
#define FND_KEY_RIGHT_ALT       ::fnd::Key::RightAlt
#define FND_KEY_RIGHT_SUPER     ::fnd::Key::RightSuper
#define FND_KEY_MENU            ::fnd::Key::Menu