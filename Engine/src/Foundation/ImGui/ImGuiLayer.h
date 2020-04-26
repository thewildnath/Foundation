#pragma once

#include "Foundation/Core/Layer.h"

namespace fnd {

  class FND_API ImGuiLayer : public Layer {
  public:
    ImGuiLayer();
    ~ImGuiLayer() override;

    static void test();

    void begin();
    void end();
  };

}