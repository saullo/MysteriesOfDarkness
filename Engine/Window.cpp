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

        m_window = glfwCreateWindow(1024, 768, "Mysteries Of Darkness", nullptr, nullptr);
        if (!m_window)
            throw std::runtime_error("Unable to create GLFW window");

        glfwMakeContextCurrent(m_window);
        glfwSwapInterval(GLFW_TRUE);
    }

    void Window::on_shutdown() { glfwTerminate(); }

    void Window::on_render()
    {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    bool Window::should_close() { return glfwWindowShouldClose(m_window); }
} // namespace Engine