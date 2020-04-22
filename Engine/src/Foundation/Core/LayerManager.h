#pragma once

#include "Foundation/fndpch.h"
#include "Foundation/Core/Layer.h"
#include "Foundation/Utils/Singleton.h"

namespace fnd {

  class FND_API LayerManager : public Singleton<LayerManager> {
  public:
    LayerManager() = default;
    ~LayerManager();

    void pushLayer(Layer* layer);
    void pushOverlay(Layer* overlay);
    void popLayer(Layer* layer);
    void popOverlay(Layer* overlay);


  private:
    std::vector<Layer*> m_layerStack;
    size_t m_layerInsertIndex = 0;
  };

}
