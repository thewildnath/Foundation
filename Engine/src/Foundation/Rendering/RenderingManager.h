#pragma once

#include "Foundation/Core.h"
#include "Foundation/Core/AbstractManager.h"

namespace fnd {

  enum class RendererAPI {
    None = 0,
    OpenGL = 1
  };

  class FND_API RenderingManager : public AbstractManager<RenderingManager> {
  public:
    RenderingManager();

    inline RendererAPI getAPI() {
      return m_API;
    }
  private:
    RendererAPI m_API;
  };

}
