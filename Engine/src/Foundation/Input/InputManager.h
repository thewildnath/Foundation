#pragma once

#include "Foundation/fndpch.h"
#include "Foundation/Core/AbstractManager.h"
#include "Foundation/Events/Event.h"
#include "Foundation/Input/KeyCodes.h"
#include "Foundation/Input/MouseCodes.h"

namespace fnd {

  class FND_API InputManager : public AbstractManager<InputManager> {
  public:
    InputManager() = default;
    ~InputManager() = default;

    void onEvent(Event& e) override;

    bool getKey(KeyCode keyCode) const;
    bool getKeyDown(KeyCode keyCode) const;
    bool getKeyUp(KeyCode keyCode) const;
    bool getMouseButton(MouseCode mouseCode) const;
    bool getMouseButtonDown(MouseCode mouseCode) const;
    bool getMouseButtonUp(MouseCode mouseCode) const;

  private:
    bool key[KEY_CODE_SIZE];
    bool mouseButton[MOUSE_CODE_SIZE];
  };

  using Input = InputManager;

}
