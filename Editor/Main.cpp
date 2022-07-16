#include <Engine/Application.hpp>
#include <exception>
#include <iostream>

int main()
{
    try
    {
        auto application = std::make_unique<Engine::Application>();
        return application->run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unhandled standard exception - " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}