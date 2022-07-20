#include <Editor/WorldEditor.hpp>
#include <Engine/Application.hpp>
#include <Engine/Utils/Ini.hpp>
#include <exception>
#include <iostream>

int main()
{
    try
    {
        auto editor_config = Engine::Utils::Ini("Assets/Config.ini");

        auto application = std::make_unique<Engine::Application>();

        auto window = Engine::Window::instance();
        window->set_maximized(editor_config.read_boolean("Screen", "Maximized", true));

        auto window_width = editor_config.read_integer("Screen", "Width", 1024);
        auto window_height = editor_config.read_integer("Screen", "Height", 768);

        window->set_resolution(window_width, window_height);

        auto world_editor = std::make_unique<Editor::WorldEditor>();
        application->add_layer(std::move(world_editor));

        return application->run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unhandled standard exception - " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}