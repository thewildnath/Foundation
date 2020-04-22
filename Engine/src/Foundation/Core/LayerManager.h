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

    // Iterators
    std::vector<Layer*>::iterator begin() { return m_layerStack.begin(); }
    std::vector<Layer*>::iterator end() { return m_layerStack.end(); }
    std::vector<Layer*>::reverse_iterator rbegin() { return m_layerStack.rbegin(); }
    std::vector<Layer*>::reverse_iterator rend() { return m_layerStack.rend(); }

    std::vector<Layer*>::const_iterator begin() const { return m_layerStack.begin(); }
    std::vector<Layer*>::const_iterator end()	const { return m_layerStack.end(); }
    std::vector<Layer*>::const_reverse_iterator rbegin() const { return m_layerStack.rbegin(); }
    std::vector<Layer*>::const_reverse_iterator rend() const { return m_layerStack.rend(); }

  private:
    std::vector<Layer*> m_layerStack;
    size_t m_layerInsertIndex = 0;
  };

}
