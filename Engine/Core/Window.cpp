#include <Engine/Core/Platform.hpp>
#include <Engine/Core/Window.hpp>
#include <cassert>

#if PLATFORM_IS_WINDOWS
#include <Engine/Core/Windows/Window.hpp>
#endif

namespace Engine::Core
{
    std::unique_ptr<Window> Window::s_instance = nullptr;

    Window &Window::instance()
    {
        if (!s_instance)
        {
#if PLATFORM_IS_WINDOWS
            s_instance = std::make_unique<Windows::Window>();
#endif
        }

        assert(s_instance);
        return *s_instance;
    }
} // namespace Engine::Core