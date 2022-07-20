#include <Editor/WorldEditor.hpp>
#include <Engine/Application.hpp>
#include <exception>
#include <iostream>

int main()
{
    try
    {
        auto application = std::make_unique<Engine::Application>();

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