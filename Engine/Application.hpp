#pragma once

#include <Engine/Graphics/Context.hpp>
#include <Engine/Gui/Context.hpp>
#include <Engine/Layer.hpp>
#include <Engine/Window.hpp>
#include <memory>
#include <vector>

namespace Engine
{
    class Application
    {
    public:
        Application();

        int run();
        void add_layer(std::unique_ptr<Layer> layer);

    private:
        std::unique_ptr<Window> m_window;
        std::unique_ptr<Graphics::Context> m_graphics;
        std::unique_ptr<Gui::Context> m_gui;
        std::vector<std::unique_ptr<Layer>> m_layers;

        void on_event(Event &event);
    };
} // namespace Engine