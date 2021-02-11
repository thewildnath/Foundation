#include "Foundation/fndpch.h"
#include "Buffer.h"

#include "Foundation/Rendering/RenderingManager.h"

#ifdef FND_PLATFORM_WINDOWS
#include "Platform/OpenGL/OpenGLBuffer.h"
#endif

namespace fnd {

  SharedPtr<VertexBuffer> VertexBuffer::create(float* vertices, size_t size) {
    switch(RenderingManager::getSingletonPtr()->getAPI()) {
      case RendererAPI::None: {
        FND_ASSERT(false, "RenderAPI::None is currently not supported");
        return nullptr;
      }
      #ifdef FND_PLATFORM_WINDOWS
      case RendererAPI::OpenGL: {
        return makeShared<OpenGLVertexBuffer>(vertices, size);
      }
      #endif
    }

    FND_ASSERT(false, "Unknown RenderAPI");
    return nullptr;
  }

  SharedPtr<IndexBuffer> IndexBuffer::create(uint32_t* indices, size_t count) {
    switch(RenderingManager::getSingletonPtr()->getAPI()) {
      case RendererAPI::None: {
        FND_ASSERT(false, "RenderAPI::None is currently not supported");
        return nullptr;
      }
      #ifdef FND_PLATFORM_WINDOWS
      case RendererAPI::OpenGL: {
        return makeShared<OpenGLIndexBuffer>(indices, count);
      }
      #endif
    }

    FND_ASSERT(false, "Unknown RenderAPI");
    return nullptr;
  }
}