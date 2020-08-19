#include "InputManager.h"

#include "Foundation/Utils/Singleton.h"

namespace fnd {

  template<> InputManager* Singleton<InputManager>::m_singleton = nullptr;

  void InputManager::onEvent(Event& e) {
    FND_DEBUG("Input event: {0}", e.toString());
  }

  bool InputManager::getKey(KeyCode keyCode) const {
    //return key[keyCode];
    return false;
  }

  bool InputManager::getKeyDown(KeyCode keyCode) const {
    return false;
  }

  bool InputManager::getKeyUp(KeyCode keyCode) const {
    return false;
  }

  bool InputManager::getMouseButton(MouseCode mouseCode) const {
    //return mouseButton[mouseCode];
    return false;
  }

  bool InputManager::getMouseButtonDown(MouseCode mouseCode) const {
    return false;
  }

  bool InputManager::getMouseButtonUp(MouseCode mouseCode) const {
    return false;
  }

}