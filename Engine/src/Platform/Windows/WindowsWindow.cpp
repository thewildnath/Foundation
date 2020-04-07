#include "WindowsWindow.h"

#include "Foundation/Events/KeyEvent.h"
#include "Foundation/Events/MouseEvent.h"
#include "Foundation/Events/WindowEvents.h"

namespace fnd {

  static uint32_t glfwWindowCount = 0;

  static void glfwErrorCallback(int error,  const char* description) {
    FND_E_ERROR("GLFW Error: ({0}): {1}", error, description);
  }

  WindowsWindow::WindowsWindow(const fnd::WindowProps &props) {
    init(props);
  }

  WindowsWindow::~WindowsWindow() {
    shutdown();
  }

  void WindowsWindow::init(const fnd::WindowProps &props) {
    data.title  = props.title;
    data.width  = props.width;
    data.height = props.height;

    FND_E_INFO("Creating window: {0} ({1} {2})", data.title, data.width, data.height);

    if (glfwWindowCount == 0) {
      int success = glfwInit();
      FND_E_ASSERT(success == GLFW_TRUE, "Could not initialise GLFW!");
      glfwSetErrorCallback(glfwErrorCallback);
    }

    window = glfwCreateWindow(
      static_cast<int>(data.width),
      static_cast<int>(data.height),
      data.title.c_str(),
      nullptr, nullptr);
    ++glfwWindowCount;

    setVSync(true);
  }

  void WindowsWindow::shutdown() {
    glfwDestroyWindow(window);
    --glfwWindowCount;

    if (glfwWindowCount == 0) {
      glfwTerminate();
    }
  }

  void WindowsWindow::onUpdate() {
    glfwPollEvents();
    glfwSwapBuffers(window);
  }

  void WindowsWindow::setVSync(bool enabled) {
    if (enabled) {
      glfwSwapInterval(1);
    } else {
      glfwSwapInterval(0);
    }

    data.vsync = enabled;
  }
}