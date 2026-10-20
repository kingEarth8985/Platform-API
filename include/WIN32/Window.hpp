#pragma once
#include <Window.hpp>

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



    };
}