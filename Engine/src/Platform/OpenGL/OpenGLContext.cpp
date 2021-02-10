#include "OpenGLContext.h"

#include <glad/glad.h>

namespace fnd {

  OpenGLContext::OpenGLContext(GLFWwindow* glfwWindow)
    : m_window(glfwWindow) {
    FND_ASSERT(glfwWindow != nullptr, "Window handle is null")
  }

  void OpenGLContext::init() {
    glfwMakeContextCurrent(m_window);

    // Initialise glad
    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    FND_ASSERT(status, "Failed to initialise glad")

    FND_INFO("OpenGL Info:");
    FND_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
    FND_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
    FND_INFO("  Version: {0}", glGetString(GL_VERSION));
  }

  void OpenGLContext::swapBuffers() {
    glfwSwapBuffers(m_window);
  }

}