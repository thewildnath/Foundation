#include <Foundation.h>
#include <imgui.h>

class ExampleLayer : public fnd::Layer {
public:

  ExampleLayer() : Layer("ExampleLayer") {};

  void onUpdate() override {
//    FND_TRACE("onUpdate from {0}", getName());

    if (INPUT->getKey(FND_KEY_W)) {
      FND_TRACE("YESSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS");
    }
  };

  void onImGui() override {
//    FND_TRACE("onImGui from {0}", getName());

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