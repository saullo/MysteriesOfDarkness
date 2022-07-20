#include <Engine/Graphics/Context.hpp>
#include <Engine/Gui/Context.hpp>
#include <Engine/Window.hpp>
#include <imgui/backends/imgui_impl_glfw.h>
#include <imgui/backends/imgui_impl_opengl3.h>

namespace Engine::Gui
{
    void Context::on_init()
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        auto &io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        auto window_instance = Window::instance();
        ImGui_ImplGlfw_InitForOpenGL(window_instance->native(), true);
        ImGui_ImplOpenGL3_Init(Graphics::Context::glsl_version);
    }

    void Context::on_shutdown()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void Context::on_update()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void Context::on_render()
    {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }
} // namespace Engine::Gui