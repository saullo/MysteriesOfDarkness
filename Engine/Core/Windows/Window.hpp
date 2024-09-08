#pragma once

#include <Engine/Core/Platform.hpp>
#include <Engine/Core/Window.hpp>
#include <Windows.h>

namespace Engine::Core::Windows
{
    class Window : public Core::Window
    {
      public:
        void init() override;
        void update() override;
        void show() override;

      private:
        HWND m_hwnd{NULL};

        static LRESULT CALLBACK s_window_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

        LRESULT CALLBACK window_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    };
} // namespace Engine::Core::Windows