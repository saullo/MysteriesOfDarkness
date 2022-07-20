#pragma once

#include <imgui.h>

namespace Engine::Gui
{
    class Context
    {
    public:
        void on_init();
        void on_shutdown();
        void on_update();
        void on_render();
    };
} // namespace Engine::Gui