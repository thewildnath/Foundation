#include "Foundation/fndpch.h"
#include "Window.h"

#include "Foundation/Core.h"

#ifdef FND_PLATFORM_WINDOWS
  #include <Platform/Windows/WindowsWindow.h>
#endif

namespace fnd {

  std::unique_ptr<Window> Window::create(const fnd::WindowProps &props) {
  #ifdef FND_PLATFORM_WINDOWS
    return makeUnique<WindowsWindow>(props);
  #else
    FND_ASSERT(false, "Unknown platform!");
    return nullptr;
  #endif
  }

}