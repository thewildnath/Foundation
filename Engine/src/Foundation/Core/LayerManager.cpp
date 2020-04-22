#include "LayerManager.h"

namespace fnd {

  template<> LayerManager* Singleton<LayerManager>::m_singleton = nullptr;

  LayerManager::~LayerManager() {
    for (Layer* layer : m_layerStack) {
      layer->onDetach();
      delete layer;
    }
  }

  void LayerManager::pushLayer(fnd::Layer* layer) {
    m_layerStack.emplace(m_layerStack.begin() + m_layerInsertIndex, layer);
    ++m_layerInsertIndex;

    FND_INFO("Pushed layer: {0}", layer->getName());
  }

  void LayerManager::pushOverlay(fnd::Layer* overlay) {
    m_layerStack.emplace_back(overlay);

    FND_INFO("Pushed overlay: {0}", overlay->getName());
  }

  void LayerManager::popLayer(fnd::Layer* layer) {
    auto it = std::find(m_layerStack.begin(), m_layerStack.begin() + m_layerInsertIndex, layer);
    if (it != m_layerStack.begin() + m_layerInsertIndex) {
      layer->onDetach();
      m_layerStack.erase(it);
      --m_layerInsertIndex;

      FND_INFO("Popped layer: {0}", layer->getName());
    }
  }

  void LayerManager::popOverlay(fnd::Layer* overlay) {
    auto it = std::find(m_layerStack.begin() + m_layerInsertIndex, m_layerStack.end(), overlay);
    if (it != m_layerStack.end()) {
      overlay->onDetach();
      m_layerStack.erase(it);

      FND_INFO("Popped overlay: {0}", overlay->getName());
    }
  }

}