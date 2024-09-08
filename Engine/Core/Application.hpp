#pragma once

#include <Engine/Core/Platform.hpp>
#include <Engine/Core/Window.hpp>

#if PLATFORM_IS_WINDOWS
#include <Windows.h>
#endif

namespace Engine::Core
{
    class DLL_EXPORT Application
    {
      public:
        enum class Type
        {
            console,
            window
        };

        static Application &instance();

        int run();
        void stop();

        void set_type(enum Type type)
        {
            m_type = type;
        }

      private:
        static std::unique_ptr<Application> s_instance;

        Type m_type{Type::console};
        bool m_should_close{false};
        Window *m_window{nullptr};

        void init();
        void loop();
        void shutdown();

        bool is_windowed();
    };
} // namespace Engine::Core

#if PLATFORM_IS_WINDOWS

#define APPLICATION_ENTRYPOINT(type)                                                                                   \
    int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine,               \
                        _In_ int nCmdShow)                                                                             \
    {                                                                                                                  \
        auto &application = Engine::Core::Application::instance();                                                     \
        application.set_type(type);                                                                                    \
        return application.run();                                                                                      \
    }

#define WINDOW_APPLICATION_ENTRYPOINT() APPLICATION_ENTRYPOINT(Engine::Core::Application::Type::window)
#define CONSOLE_APPLICATION_ENTRYPOINT() APPLICATION_ENTRYPOINT(Engine::Core::Application::Type::console)

#endif