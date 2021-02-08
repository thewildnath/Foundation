#include "InputManager.h"

#include "Foundation/Events/KeyEvent.h"
#include "Foundation/Events/MouseEvent.h"
#include "Foundation/Utils/Singleton.h"

namespace fnd {

  template<> InputManager* Singleton<InputManager>::m_singleton = nullptr;

  void InputManager::onEvent(Event& e) {
    FND_DEBUG("Input event: {0}", e.toString());

    EventDispatcher dispatcher(e);
    dispatcher.dispatch<KeyPressedEvent>([this](KeyPressedEvent e) {
      key[e.getKeyCode()] = true;
      return true;
    });
    dispatcher.dispatch<KeyReleasedEvent>([this](KeyReleasedEvent e) {
      key[e.getKeyCode()] = false;
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