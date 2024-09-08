#include <Engine/Core/Application.hpp>
#include <Engine/Core/Windows/Window.hpp>
#include <cassert>

namespace Engine::Core::Windows
{
    void Window::init()
    {
        const auto class_name = TEXT("Mysteries_Of_Darkness_CLASS_NAME");
        const auto hInstance = GetModuleHandle(NULL);

        WNDCLASS wnd_class = {};
        wnd_class.lpfnWndProc = s_window_proc;
        wnd_class.hInstance = hInstance;
        wnd_class.lpszClassName = class_name;
        wnd_class.hCursor = LoadCursor(NULL, IDC_ARROW);
        wnd_class.hIcon = LoadIcon(NULL, IDI_APPLICATION);
        wnd_class.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
        wnd_class.style = CS_HREDRAW | CS_VREDRAW;

        if (!RegisterClass(&wnd_class))
            return;

        m_hwnd = CreateWindow(class_name, TEXT("Mysteries Of Darkness"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
                              CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, this);
        if (m_hwnd == NULL)
            return;
    }

    void Window::show()
    {
        ShowWindow(m_hwnd, SW_SHOWDEFAULT);
    }

    void Window::update()
    {
        MSG msg = {};
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                auto &application = Application::instance();
                application.stop();

                return;
            }

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    LRESULT CALLBACK Window::window_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        switch (uMsg)
        {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, uMsg, wParam, lParam);
        }

        return 0;
    }

    LRESULT CALLBACK Window::s_window_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        Window *instance;
        if (uMsg == WM_NCCREATE)
        {
            auto lpcs = reinterpret_cast<LPCREATESTRUCT>(lParam);
            instance = static_cast<Window *>(lpcs->lpCreateParams);

            SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(instance));
        }
        else
        {
            auto pointer = GetWindowLongPtr(hWnd, GWLP_USERDATA);
            instance = reinterpret_cast<Window *>(pointer);
        }

        if (instance)
            return instance->window_proc(hWnd, uMsg, wParam, lParam);

        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
} // namespace Engine::Core::Windows