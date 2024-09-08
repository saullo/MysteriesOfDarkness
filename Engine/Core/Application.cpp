#include <Engine/Core/Application.hpp>
#include <cassert>

namespace Engine::Core
{
    std::unique_ptr<Application> Application::s_instance = nullptr;

    Application &Application::instance()
    {
        if (!s_instance)
            s_instance = std::make_unique<Application>();

        assert(s_instance);
        return *s_instance;
    }

    int Application::run()
    {
        init();
        loop();
        shutdown();

        return EXIT_SUCCESS;
    }

    void Application::stop()
    {
        m_should_close = true;
    }

    void Application::init()
    {
        if (is_windowed())
        {
            m_window = &Window::instance();
            m_window->init();
        }
    }

    void Application::loop()
    {
        if (is_windowed())
        {
            m_window->show();
        }

        while (!m_should_close)
        {
            if (is_windowed())
            {
                m_window->update();
            }
        }
    }

    void Application::shutdown()
    {
    }

    bool Application::is_windowed()
    {
        return m_type == Type::window;
    }
} // namespace Engine::Core