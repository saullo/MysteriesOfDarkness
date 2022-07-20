#include <Editor/WorldEditor.hpp>
#include <Engine/Gui/Context.hpp>

namespace Editor
{
    void WorldEditor::on_gui()
    {
        auto viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->WorkPos);
        ImGui::SetNextWindowSize(viewport->WorkSize);
        ImGui::SetNextWindowViewport(viewport->ID);

        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

        ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
                                        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
                                        ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

        ImGui::Begin("WorldEditor", nullptr, window_flags);
        ImGui::PopStyleVar(3);

        auto dockspace_id = ImGui::GetID("WorldEditor_Dockspace");
        if (ImGui::DockBuilderGetNode(dockspace_id) == nullptr)
        {
            ImGui::DockBuilderRemoveNode(dockspace_id);
            ImGui::DockBuilderAddNode(dockspace_id, ImGuiDockNodeFlags_DockSpace);
            ImGui::DockBuilderSetNodeSize(dockspace_id, viewport->Size);

            auto main_node_id = dockspace_id;
            auto top_node_id = ImGui::DockBuilderSplitNode(main_node_id, ImGuiDir_Up, 0.5f, nullptr, &main_node_id);
            auto right_node_id =
                ImGui::DockBuilderSplitNode(main_node_id, ImGuiDir_Right, 0.5f, nullptr, &main_node_id);
            auto left_node_id = ImGui::DockBuilderSplitNode(main_node_id, ImGuiDir_Left, 0.5f, nullptr, &main_node_id);
            auto bottom_node_id =
                ImGui::DockBuilderSplitNode(main_node_id, ImGuiDir_Down, 0.5f, nullptr, &main_node_id);

            for (const auto &panel : m_panels)
            {
                switch (panel->dock_direction())
                {
                case Panels::Base::DockDirection::top:
                    ImGui::DockBuilderDockWindow(panel->name().c_str(), top_node_id);
                    break;
                case Panels::Base::DockDirection::bottom:
                    ImGui::DockBuilderDockWindow(panel->name().c_str(), bottom_node_id);
                    break;
                case Panels::Base::DockDirection::left:
                    ImGui::DockBuilderDockWindow(panel->name().c_str(), left_node_id);
                    break;
                case Panels::Base::DockDirection::right:
                    ImGui::DockBuilderDockWindow(panel->name().c_str(), right_node_id);
                    break;
                default:
                    ImGui::DockBuilderDockWindow(panel->name().c_str(), main_node_id);
                }
            }

            ImGui::DockBuilderFinish(dockspace_id);
        }

        ImGui::DockSpace(dockspace_id);
        ImGui::End();

        for (const auto &panel : m_panels)
            panel->on_gui();
    }
} // namespace Editor