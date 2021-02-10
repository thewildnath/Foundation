#pragma once

#include <GLFW/glfw3.h>

#include "Foundation/fndpch.h"
#include "Foundation/Rendering/RenderingContext.h"

namespace fnd {

  class OpenGLContext : public RenderingContext {
  public:
    OpenGLContext(GLFWwindow* glfwWindow);

    virtual void init();
    virtual void swapBuffers();

  private:
    GLFWwindow* m_window;
  };

}

