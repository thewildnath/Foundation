#pragma once

#include "Foundation/Core/Layer.h"

namespace fnd {

  class FND_API ImGuiLayer : public Layer {
  public:
    ImGuiLayer();
    ~ImGuiLayer();

    virtual void onUpdate() override;
    virtual void onImGui() override;

  private:
    float m_time;
  };

}