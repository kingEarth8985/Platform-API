#include <WindowFactory.hpp>

int main()
{
    Platform::WindowDescriptor windowDescriptor{
        .Width = 1280,
        .Height = 720,
        .Title = "Example Window",
    };


    Platform::WindowPtr window {windowDescriptor};

    window.Init();
    window.Show();

    bool running = true;
    while (running)
    {
        window.PollEvents();
        if (window.ShouldClose())
        {
            running = false;
        }
    }

    return 0;
}