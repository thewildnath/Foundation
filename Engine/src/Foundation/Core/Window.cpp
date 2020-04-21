#include "Window.h"

#ifdef FND_PLATFORM_WINDOWS
  #include <Platform/Windows/WindowsWindow.h>
#endif

namespace fnd {

  std::unique_ptr<Window> Window::create(const fnd::WindowProps &props) {
  #ifdef FND_PLATFORM_WINDOWS
    return std::make_unique<WindowsWindow>(props);
  #else
    FND_ASSERT(false, "Unknown platform!");
    return nullptr;
  #endif
  }

}