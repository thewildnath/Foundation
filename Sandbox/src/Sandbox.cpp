#include <Foundation.h>

class SandboxApplication : public fnd::Application {
public:
  SandboxApplication() = default;
  ~SandboxApplication() override = default;
};

fnd::Application* fnd::createApplication() {
  return new SandboxApplication();
}