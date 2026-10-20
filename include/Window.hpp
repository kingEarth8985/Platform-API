#pragma once
#include <string>
#include <memory>
#include <cstdint>

namespace Platform
{
    struct WindowDescriptor
    {
        uint32_t Width;
        uint32_t Height;
        std::string Title;
    };

    class Window
    {
    public:
        Window(const WindowDescriptor& descriptor)
            : m_Descriptor(descriptor)
        {
        }

        virtual ~Window() = default;

        virtual void InitPlatformWindow() = 0;
        virtual void Show() = 0;
        virtual void PollEvents() = 0;

    protected:
        WindowDescriptor m_Descriptor;
    };
}