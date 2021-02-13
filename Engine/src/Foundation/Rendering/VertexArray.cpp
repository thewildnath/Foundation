#include "Foundation/fndpch.h"
#include "VertexArray.h"

#include "Foundation/Core.h"
#include "Foundation/Rendering/RenderingManager.h"

#ifdef FND_PLATFORM_WINDOWS
#include "Platform/OpenGL/OpenGLVertexArray.h"
#endif

namespace fnd {

  SharedPtr<VertexArray> VertexArray::create() {
    switch(RenderingManager::getSingletonPtr()->getAPI()) {
      case RendererAPI::None: FND_ASSERT(false, "RenderAPI::None is currently not supported") return nullptr;
      #ifdef FND_PLATFORM_WINDOWS
      case RendererAPI::OpenGL: return makeShared<OpenGLVertexArray>();
      #endif
    }

    FND_ASSERT(false, "Unknown RenderAPI");
    return nullptr;
  }

}
