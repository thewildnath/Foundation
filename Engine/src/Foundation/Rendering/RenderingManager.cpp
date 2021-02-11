#include "Foundation/fndpch.h"
#include "RenderingManager.h"

namespace fnd {

  template<> RenderingManager* Singleton<RenderingManager>::m_singleton = nullptr;

  RenderingManager::RenderingManager() {
    m_API = RendererAPI::OpenGL;
  }

}