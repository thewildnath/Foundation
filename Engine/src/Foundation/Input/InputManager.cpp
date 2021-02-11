#include "Foundation/fndpch.h"
#include "InputManager.h"

#include "Foundation/Events/KeyEvent.h"
#include "Foundation/Events/MouseEvent.h"
#include "Foundation/Utils/Singleton.h"

namespace fnd {

  template<> InputManager* Singleton<InputManager>::m_singleton = nullptr;

  void InputManager::onEvent(Event& e) {
    EventDispatcher dispatcher(e);
    dispatcher.dispatch<KeyPressedEvent>([this](KeyPressedEvent e) {
      key[e.getKeyCode()] = true;
      return true;
    });
    dispatcher.dispatch<KeyReleasedEvent>([this](KeyReleasedEvent e) {
      key[e.getKeyCode()] = false;
      return true;
    });

    dispatcher.dispatch<MouseButtonPressedEvent>([this](MouseButtonPressedEvent e) {
      mouseButton[e.getMouseCode()] = true;
      return true;
    });
    dispatcher.dispatch<MouseButtonReleasedEvent>([this](MouseButtonReleasedEvent e) {
      mouseButton[e.getMouseCode()] = false;
      return true;
    });

    dispatcher.dispatch<MouseMovedEvent>([this](MouseMovedEvent e) {
      mouseX = e.getX();
      mouseY = e.getY();
      return true;
    });
  }

  bool InputManager::getKey(KeyCode keyCode) const {
    return key[keyCode];
  }

  bool InputManager::getKeyDown(KeyCode keyCode) const {
    return false;
  }

  bool InputManager::getKeyUp(KeyCode keyCode) const {
    return false;
  }

  bool InputManager::getMouseButton(MouseCode mouseCode) const {
    return mouseButton[mouseCode];
  }

  bool InputManager::getMouseButtonDown(MouseCode mouseCode) const {
    return false;
  }

  bool InputManager::getMouseButtonUp(MouseCode mouseCode) const {
    return false;
  }

  float InputManager::getMouseX() const {
    return mouseX;
  }

  float InputManager::getMouseY() const {
    return mouseY;
  }

}