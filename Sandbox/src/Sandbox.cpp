#include <Foundation.h>
#include <imgui.h>

class ExampleLayer : public fnd::Layer {
public:

  ExampleLayer() : Layer("ExampleLayer") {};

  void onUpdate() override {
    FND_INFO("Update from {0}", getName());
  };

  void onImGui() override {
    FND_DEBUG("Update ImGui");
    
    static bool show = true;
    ImGui::ShowDemoWindow(&show);

    ImGui::Begin("Example");
    ImGui::Text("-lorem ipsum-");
    ImGui::End();
  }
};

class SandboxApplication : public fnd::Application {
public:
  SandboxApplication() {
    pushLayer(new ExampleLayer());
  };
  ~SandboxApplication() override = default;
};

fnd::Application* fnd::createApplication() {
  return new SandboxApplication();
}