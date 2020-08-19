#pragma once

#include "Foundation/Events/Event.h"
#include "Foundation/Utils/Singleton.h"

namespace fnd {

  template <typename T>
  class AbstractManager : public Singleton<T> {
  public:
    AbstractManager() = default;
    ~AbstractManager() = default;

    virtual void onEvent(Event &e) {};

    virtual void startUp() {};
    virtual void shutDown() {};
    virtual void onUpdate() {};
  };

}

