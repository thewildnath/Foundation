#include <Foundation.h>

class ExampleLayer : public fnd::Layer {
public:

  ExampleLayer() : Layer("ExampleLayer") {};

  void onUpdate() override {
    FND_INFO("Update from {0}", getName());
  };
};

class SandboxApplication : public fnd::Application {
public:
  SandboxApplication() {
    pushLayer(new ExampleLayer());
    pushLayer(new fnd::ImGuiLayer());
  };
  ~SandboxApplication() override = default;
};

fnd::Application* fnd::createApplication() {
  return new SandboxApplication();
}