#pragma once

#include "Foundation/Core/Layer.h"

namespace fnd {

  class ImGuiLayer : public Layer {
  public:
    ImGuiLayer();
    ~ImGuiLayer();

    virtual void onImGui() override;
  };

}