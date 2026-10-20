#include <Window.hpp>
#include <WindowFactory.hpp>

namespace Platform
{
    std::unique_ptr<Window> CreateWindow(const WindowDescriptor& descriptor)
    {
        #ifdef PLATFORM_WINDOWS
            return std::make_unique<Win32Window>(descriptor);
        #elif PLATFORM_LINUX
            //return std::make_unique<X11Window>(descriptor);
        #endif
    }
}