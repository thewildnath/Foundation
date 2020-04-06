#include "Application.h"

#include "Foundation/Events/KeyEvent.h"
#include "Foundation/Events/MouseEvent.h"
#include "Foundation/Events/WindowEvents.h"
#include "Foundation/Log.h"

namespace fnd {

  Application::Application() = default;

  Application::~Application() = default;

  void Application::run() {
//    MouseMovedEvent e(1233, 45);
    MouseButtonPressedEvent e(MouseCode::ButtonLeft);
    FND_E_DEBUG(e.toString());
    if (e.isInCategory(EventCategory::Input)) FND_E_DEBUG("input");
    if (e.isInCategory(EventCategory::Mouse)) FND_E_DEBUG("mouse");
    if (e.isInCategory(EventCategory::MouseButton)) FND_E_DEBUG("mouse button");
  }

}