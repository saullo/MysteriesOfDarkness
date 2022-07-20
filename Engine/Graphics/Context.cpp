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

    void Context::on_event(Event &event)
    {
        EventCaller caller(event);
        caller.call<FramebufferSizeEvent>(EVENT_HANDLER(on_framebuffer_size));
    }

    void Context::on_framebuffer_size(FramebufferSizeEvent &event) {
        glViewport(0, 0, event.width(), event.height());
    }
} // namespace Engine::Graphics