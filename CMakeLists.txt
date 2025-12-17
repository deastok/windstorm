cmake_minimum_required(VERSION 3.22)

project(
    windstorm
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(windstorm
        src/app/main.cpp
        src/core/version.cpp
)

target_include_directories(windstorm PRIVATE include)

target_compile_options(windstorm PRIVATE -Wall -Wextra -Wpedantic)