#pragma once
#include <memory>
#include <Window.hpp>

namespace Platform
{
    std::unique_ptr<Window> CreatePlatformWindow(const WindowDescriptor& descriptor);

    class WindowPtr
    {
    public:
        explicit WindowPtr(const WindowDescriptor& descriptor)
        {
            m_Window = CreatePlatformWindow(descriptor);
        }

        void Init()
        {
            m_Window->InitPlatformWindow();
        }

        void Show()
        {
            m_Window->Show();
        }

        void PollEvents()
        {
            m_Window->PollEvents();
        }

        bool ShouldClose()
        {
            return m_Window->ShouldClose();
        }

    private:
        std::unique_ptr<Window> m_Window;
    };
}