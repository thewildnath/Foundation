#include "WindowsWindow.h"

#include "Foundation/Events/KeyEvent.h"
#include "Foundation/Events/MouseEvent.h"
#include "Foundation/Events/WindowEvents.h"
#include "Foundation/Input/KeyCodes.h"
#include "Foundation/Input/MouseCodes.h"

namespace fnd {

  static uint32_t s_glfwWindowCount = 0;

  static void glfwErrorCallback(int error,  const char* description) {
    FND_ERROR("GLFW Error: ({0}): {1}", error, description);
  }

  WindowsWindow::WindowsWindow(const fnd::WindowProps &props) {
    init(props);
  }

  WindowsWindow::~WindowsWindow() {
    shutdown();
  }

  void WindowsWindow::init(const fnd::WindowProps &props) {
    m_data.title  = props.title;
    m_data.width  = props.width;
    m_data.height = props.height;

    FND_INFO("Creating window: {0} ({1} {2})", m_data.title, m_data.width, m_data.height);

    if (s_glfwWindowCount == 0) {
      int success = glfwInit();
      FND_ASSERT(success == GLFW_TRUE, "Could not initialise GLFW!");
      glfwSetErrorCallback(glfwErrorCallback);
    }

    m_window = glfwCreateWindow(
      static_cast<int>(m_data.width),
      static_cast<int>(m_data.height),
      m_data.title.c_str(),
      nullptr, nullptr);
    ++s_glfwWindowCount;

    setVSync(true);

    // Set glfw callbacks
    glfwSetWindowUserPointer(m_window, &m_data);

    glfwSetWindowCloseCallback(m_window, [](GLFWwindow* glfwWindow) {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(glfwWindow));

      WindowCloseEvent e;
      data.eventCallback(e);
    });

    glfwSetWindowSizeCallback(m_window, [](GLFWwindow* glfwWindow, int width, int height) {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(glfwWindow));
      data.width = width;
      data.height = height;

      WindowResizedEvent e(data.width, data.height);
      data.eventCallback(e);
    });

    glfwSetKeyCallback(m_window, [](GLFWwindow* glfwWindow, int key, int scancode, int action, int mods) {
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
          FND_WARN("Unknown GLFW key action type: {0}", action);
        }
      }
    });

    glfwSetMouseButtonCallback(m_window, [](GLFWwindow* glfwWindow, int button, int action, int mods) {
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
          FND_WARN("Unknown GLFW mouse action type: {0}", action);
        }
      }
    });

    glfwSetScrollCallback(m_window, [](GLFWwindow* glfwWindow, double xOffset, double yOffset) {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(glfwWindow));

      MouseScrolledEvent e(static_cast<float>(xOffset), static_cast<float>(yOffset));
      data.eventCallback(e);
    });

    glfwSetCursorPosCallback(m_window, [](GLFWwindow* glfwWindow, double xPos, double yPos) {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(glfwWindow));

      MouseMovedEvent e(static_cast<float>(xPos), static_cast<float>(yPos));
      data.eventCallback(e);
    });
  }

  void WindowsWindow::shutdown() {
    glfwDestroyWindow(m_window);
    --s_glfwWindowCount;

    if (s_glfwWindowCount == 0) {
      glfwTerminate();
    }
  }

  void WindowsWindow::onUpdate() {
    glfwSwapBuffers(m_window);
    glfwPollEvents();
  }

  void WindowsWindow::setVSync(bool enabled) {
    if (enabled) {
      glfwSwapInterval(1);
    } else {
      glfwSwapInterval(0);
    }

    m_data.vsync = enabled;
  }
}