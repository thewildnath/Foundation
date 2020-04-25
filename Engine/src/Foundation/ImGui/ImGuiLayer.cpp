#include "ImGuiLayer.h"

#include <imgui.h>
#include <GLFW/glfw3.h>

#include "Platform/ImGui/imgui_impl_glfw.h"
#include "Platform/ImGui/imgui_impl_opengl3.h"

#include "Foundation/Core/Application.h"

namespace fnd {

  ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {
    IMGUI_CHECKVERSION();

    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGuiIO& io = ImGui::GetIO();
    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

    ImGui_ImplOpenGL3_Init("#version 410");

  }

  ImGuiLayer::~ImGuiLayer() {

  }

  void ImGuiLayer::onUpdate() {
    FND_DEBUG("Update imgui");

    ImGuiIO& io = ImGui::GetIO();
    Application* app = Application::getSingletonPtr();
    io.DisplaySize = ImVec2(app->getWindow()->getWidth(), app->getWindow()->getHeight());

    float time = (float)glfwGetTime();
    io.DeltaTime = m_time > 0.0f ? (time - m_time) : (1.0f / 60.0f);
    m_time = time;

    ImGui_ImplOpenGL3_NewFrame();
    ImGui::NewFrame();

    static bool show = true;
    ImGui::ShowDemoWindow(&show);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
  }

  void ImGuiLayer::onImGui() {

  };

}