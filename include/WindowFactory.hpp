#pragma once
#include <memory>
#include <WIN32/Window.hpp>

namespace Platform
{
    std::unique_ptr<Window> CreateWindow(const WindowDescriptor& descriptor);
}