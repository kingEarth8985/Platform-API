#include <Window.hpp>
#include <WindowFactory.hpp>

#ifdef PLATFORM_WINDOWS
    #include <WIN32/Window.hpp>
#elif PLATFORM_LINUX
    #include <LINUX/Window.hpp>
#endif

namespace Platform
{
    std::unique_ptr<Window> CreatePlatformWindow(const WindowDescriptor& descriptor)
    {
        #ifdef PLATFORM_WINDOWS
            return std::make_unique<Win32Window>(descriptor);
        #elif PLATFORM_LINUX
            //return std::make_unique<X11Window>(descriptor);
        #endif
    }
}