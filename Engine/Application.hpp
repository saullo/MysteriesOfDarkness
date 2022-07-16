#pragma once

#include <Engine/Window.hpp>
#include <memory>

namespace Engine
{
    class Application
    {
    public:
        Application();

        int run();

    private:
        std::unique_ptr<Window> m_window;
    };
} // namespace Engine