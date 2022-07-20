#include <Engine/Graphics/Context.hpp>
#include <Engine/Platform.hpp>
#include <stdexcept>

namespace Engine::Graphics
{
    void Context::on_init()
    {
        if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
            throw std::runtime_error("Unable to load GLAD");
    }

    void Context::on_render()
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
} // namespace Engine::Graphics