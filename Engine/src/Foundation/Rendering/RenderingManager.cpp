#include "Foundation/fndpch.h"
#include "RenderingManager.h"

namespace fnd {

  template<> RenderingManager* Singleton<RenderingManager>::s_singleton = nullptr;

  RenderingManager::RenderingManager() {
    m_API = RendererAPI::OpenGL;
  }

}