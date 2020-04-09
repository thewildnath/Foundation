#include "WindowsWindow.h"

#include "Foundation/Events/KeyEvent.h"
#include "Foundation/Events/MouseEvent.h"
#include "Foundation/Events/WindowEvents.h"
#include "Foundation/Input/KeyCodes.h"
#include "Foundation/Input/MouseCodes.h"

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

    // Set glfw callbacks
    glfwSetWindowUserPointer(window, &data);

    glfwSetWindowCloseCallback(window, [](GLFWwindow* glfwWindow) {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(glfwWindow));

      WindowCloseEvent e;
      data.eventCallback(e);
    });

    glfwSetWindowSizeCallback(window, [](GLFWwindow* glfwWindow, int width, int height) {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(glfwWindow));
      data.width = width;
      data.height = height;

      WindowResizedEvent e(data.width, data.height);
      data.eventCallback(e);
    });

    glfwSetKeyCallback(window, [](GLFWwindow* glfwWindow, int key, int scancode, int action, int mods) {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(glfwWindow));

      switch (action) {
        case GLFW_PRESS: {
          KeyPressedEvent e(static_cast<KeyCode>(key), 0);
          data.eventCallback(e);
          break;
        }
        case GLFW_RELEASE: {
          KeyReleasedEvent e(static_cast<KeyCode>(key));
          data.eventCallback(e);
          break;
        }
        case GLFW_REPEAT: {
          KeyPressedEvent e(static_cast<KeyCode>(key), 1);
          data.eventCallback(e);
          break;
        }
        default: {
          FND_E_WARN("Unknown GLFW key action type: {0}", action);
        }
      }
    });

    glfwSetMouseButtonCallback(window, [](GLFWwindow* glfwWindow, int button, int action, int mods) {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(glfwWindow));

      switch (action) {
        case GLFW_PRESS: {
          MouseButtonPressedEvent e(static_cast<MouseCode>(button));
          data.eventCallback(e);
          break;
        }
        case GLFW_RELEASE: {
          MouseButtonReleasedEvent e(static_cast<MouseCode>(button));
          data.eventCallback(e);
          break;
        }
        default: {
          FND_E_WARN("Unknown GLFW mouse action type: {0}", action);
        }
      }
    });

    glfwSetScrollCallback(window, [](GLFWwindow* glfwWindow, double xOffset, double yOffset) {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(glfwWindow));

      MouseScrolledEvent e(static_cast<float>(xOffset), static_cast<float>(yOffset));
      data.eventCallback(e);
    });

    glfwSetCursorPosCallback(window, [](GLFWwindow* glfwWindow, double xPos, double yPos) {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(glfwWindow));

      MouseMovedEvent e(static_cast<float>(xPos), static_cast<float>(yPos));
      data.eventCallback(e);
    });
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