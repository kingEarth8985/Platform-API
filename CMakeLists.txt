cmake_minimum_required(VERSION 3.10.0)
project(Platform VERSION 0.1.0 LANGUAGES C CXX)

add_library(Platform 
src/Window.cpp
src/WIN32/Window.cpp
)

target_compile_definitions(Platform
    PUBLIC
        UNICODE
        _UNICODE
)

if(WIN32)
    target_compile_definitions(
        Platform
        PUBLIC PLATFORM_WINDOWS
    )
elseif(UNIX)
    target_compile_definitions(
        Platform
        PUBLIC PLATFORM_LINUX
    )
endif()

target_include_directories(Platform PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(Platform
    PRIVATE
        user32
        gdi32
)