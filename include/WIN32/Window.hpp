#pragma once

#include <Window.hpp>
#include <Windows.h>

namespace Platform
{
    class Win32Window : public Window
    {
    public:
        Win32Window(const WindowDescriptor& descriptor)
            : Window(descriptor)
        {
        }

        void InitPlatformWindow() override;
        void Show() override;
        void PollEvents() override;

    private:
        HWND m_WindowHandle = nullptr;
        HINSTANCE m_InstanceHandle = nullptr;

        static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    };
}