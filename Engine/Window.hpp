#pragma once

#include <Engine/Event.hpp>
#include <Engine/Platform.hpp>
#include <functional>

namespace Engine
{
    class Window
    {
    public:
        using EventHandler = std::function<void(Event &)>;

        static Window *instance() { return m_instance; }

        Window();

        void on_init();
        void on_shutdown();
        void on_render();

        GLFWwindow *native() { return m_window; }
        bool should_close();

        void set_event_handler(const EventHandler &handler) { m_event_handler = handler; }
        void set_maximized(bool mode) { m_maximized = mode; }
        void set_resolution(int width, int height) { m_width = width, m_height = height; }

    private:
        static Window *m_instance;

        GLFWwindow *m_window{nullptr};
        EventHandler m_event_handler;
        bool m_maximized{false};
        int m_width{1024};
        int m_height{768};
    };
} // namespace Engine