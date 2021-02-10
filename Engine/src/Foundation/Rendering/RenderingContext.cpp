#include "RenderingContext.h"

#include "Platform/OpenGL/OpenGLContext.h"

namespace fnd {

  UniquePtr<RenderingContext> RenderingContext::create(void* window) {
    return makeUnique<OpenGLContext>(static_cast<GLFWwindow*>(window));
  }

}