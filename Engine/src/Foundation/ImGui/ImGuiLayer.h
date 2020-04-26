#pragma once

#include "Foundation/Core/Layer.h"

namespace fnd {

  class FND_API ImGuiLayer : public Layer {
  public:
    ImGuiLayer();
    ~ImGuiLayer() override;

    virtual void onUpdate() override;

    void begin();
    void end();

  private:
    float m_time;
  };

}