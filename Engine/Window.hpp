#pragma once

#include <Engine/Platform.hpp>

namespace Engine
{
    class Window
    {
    public:
        static Window *instance() { return m_instance; }

        Window();

        void on_init();
        void on_shutdown();
        void on_render();

        GLFWwindow *native() { return m_window; }
        bool should_close();

    private:
        static Window *m_instance;

        GLFWwindow *m_window{nullptr};
    };
} // namespace Engine