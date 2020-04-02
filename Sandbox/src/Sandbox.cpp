#include <Foundation.h>

class Sandbox : public fnd::Application {
public:
  Sandbox() = default;
  ~Sandbox() = default;
};

fnd::Application* fnd::createApplication() {
  return new Sandbox();
}