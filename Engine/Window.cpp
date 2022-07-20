#include <Engine/Graphics/Context.hpp>
#include <Engine/Window.hpp>
#include <stdexcept>

namespace Engine
{
    Window *Window::m_instance = nullptr;

    Window::Window() { m_instance = this; }

    void Window::on_init()
    {
        if (!glfwInit())
            throw std::runtime_error("Unable to init GLFW");

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, Graphics::Context::major_version);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, Graphics::Context::minor_version);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        m_window = glfwCreateWindow(1024, 768, "Mysteries Of Darkness", nullptr, nullptr);
        if (!m_window)
            throw std::runtime_error("Unable to create GLFW window");

        glfwMakeContextCurrent(m_window);
        glfwSwapInterval(GLFW_TRUE);
        glfwSetWindowUserPointer(m_window, this);

        glfwSetFramebufferSizeCallback(m_window, [](auto window, auto width, auto height) {
            auto window_class = reinterpret_cast<Window *>(glfwGetWindowUserPointer(window));

            FramebufferSizeEvent event(width, height);
            window_class->m_event_handler(event);
        });
    }

    void Window::on_shutdown() { glfwTerminate(); }

    void Window::on_render()
    {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    bool Window::should_close() { return glfwWindowShouldClose(m_window); }
} // namespace Engine