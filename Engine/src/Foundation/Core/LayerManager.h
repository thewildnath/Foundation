#pragma once

#include <vector>

#include "Foundation/Core.h"
#include "Foundation/Core/AbstractManager.h"
#include "Foundation/Core/Layer.h"

namespace fnd {

  class FND_API LayerManager : public AbstractManager<LayerManager> {
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
    std::vector<Layer*> m_layerStack; // TODO: UniquePtr/ LayerManager should own all layers
    size_t m_layerInsertIndex = 0;
  };

}
