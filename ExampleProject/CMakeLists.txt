cmake_minimum_required(VERSION 3.10.0)
project(ExampleProject VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ExampleProject main.cpp)

add_subdirectory(.. PlatformAPI-build)

target_link_libraries(
    ExampleProject
    PRIVATE
    Platform
)

target_include_directories(ExampleProject PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../include)