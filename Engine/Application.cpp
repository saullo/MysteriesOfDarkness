#include <Engine/Application.hpp>

namespace Engine
{
    Application::Application()
    {
        m_window = std::make_unique<Window>();
        m_window->set_event_handler(EVENT_HANDLER(on_event));

        m_graphics = std::make_unique<Graphics::Context>();
        m_gui = std::make_unique<Gui::Context>();
    }

    int Application::run()
    {
        m_window->on_init();
        m_graphics->on_init();
        m_gui->on_init();

        while (!m_window->should_close())
        {
            m_graphics->on_render();
            m_gui->on_render();
            m_window->on_render();
        }

        m_gui->on_shutdown();
        m_window->on_shutdown();

        return EXIT_SUCCESS;
    }

    void Application::on_event(Event &event) { m_graphics->on_event(event); }
} // namespace Engine