//WIN32
#include <WIN32/Window.hpp>

namespace Platform
{
    void Win32Window::InitPlatformWindow()
    {
        m_InstanceHandle = GetModuleHandle(nullptr);

        WNDCLASS wc{};
        wc.lpfnWndProc = WindowProc;
        wc.hInstance = m_InstanceHandle;
        wc.lpszClassName = L"PlatformWindow";

        RegisterClass(&wc);

        m_WindowHandle = CreateWindowEx(
            0,
            L"PlatformWindow",
            std::wstring(
                m_Descriptor.Title.begin(),
                m_Descriptor.Title.end()).c_str(),
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            static_cast<int>(m_Descriptor.Width),
            static_cast<int>(m_Descriptor.Height),
            nullptr,
            nullptr,
            m_InstanceHandle,
            this);
    }

    LRESULT CALLBACK Win32Window::WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        auto* window = reinterpret_cast<Win32Window*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
        
        switch (msg)
        {
            case WM_NCCREATE:
            {
                auto* createStruct =
                    reinterpret_cast<CREATESTRUCT*>(lParam);

                SetWindowLongPtr(
                    hwnd,
                    GWLP_USERDATA,
                    reinterpret_cast<LONG_PTR>(
                        createStruct->lpCreateParams));

                return TRUE;
            }

            case WM_CLOSE:
            {
                window->m_ShouldClose = true;
                return 0;
            }

            case WM_DESTROY:
            {
                PostQuitMessage(0);
                return 0;
            }

            default:
            {
                return DefWindowProc(
                    hwnd,
                    msg,
                    wParam,
                    lParam);
            }
        }
    }

    void Win32Window::Show()
    {
        ShowWindow(m_WindowHandle, SW_SHOW);
        UpdateWindow(m_WindowHandle);
    }

    void Win32Window::PollEvents()
    {
        MSG msg{};

        while (PeekMessage(
            &msg,
            nullptr,
            0,
            0,
            PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                m_ShouldClose = true;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
}