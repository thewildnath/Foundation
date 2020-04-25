#pragma once

#include "Foundation/fndpch.h"
#include <Foundation/Events/Event.h>

namespace fnd {

  class FND_API Layer {
  public:
    explicit Layer(const std::string& name);
    virtual ~Layer() = default;

    virtual void onAttach() {};
    virtual void onDetach() {};
    virtual void onEvent(Event& e) {};
    virtual void onUpdate() {};
    virtual void onImGui() {};

    inline const std::string& getName() const { return m_name; }
  private:
    std::string m_name;
  };

}