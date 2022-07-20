#pragma once

#include <Engine/Graphics/Context.hpp>
#include <Engine/Gui/Context.hpp>
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
        std::unique_ptr<Graphics::Context> m_graphics;
        std::unique_ptr<Gui::Context> m_gui;
    };
} // namespace Engine