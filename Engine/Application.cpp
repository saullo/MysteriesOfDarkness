#include <Engine/Application.hpp>

namespace Engine
{
    Application::Application() { m_window = std::make_unique<Window>(); }

    int Application::run()
    {
        m_window->on_init();

        while (!m_window->should_close())
        {
            m_window->on_render();
        }

        m_window->on_shutdown();

        return EXIT_SUCCESS;
    }
} // namespace Engine