#pragma once

#include "Foundation/Core.h"
#include "Foundation/Core/Layer.h"

namespace fnd {

  class FND_API ImGuiLayer : public Layer {
  public:
    ImGuiLayer();
    ~ImGuiLayer() override;

    void begin();
    void end();
  };

}