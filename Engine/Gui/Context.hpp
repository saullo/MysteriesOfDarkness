#pragma once

namespace Engine::Gui
{
    class Context
    {
    public:
        void on_init();
        void on_shutdown();
        void on_render();
    };
} // namespace Engine::Gui