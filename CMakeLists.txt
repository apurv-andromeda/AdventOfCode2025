cmake_minimum_required(VERSION 3.14)
project(AdventOfCode2025 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_custom_target(copy-compile-commands ALL
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_SOURCE_DIR}/compile_commands.json
    DEPENDS ${CMAKE_BINARY_DIR}/compile_commands.json
)

# Use C++17 (or 20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include headers
include_directories(include)

# Collect all source files in src/
file(GLOB SOURCES src/*.cpp)

# Create executable
add_executable(AdventOfCode2025 ${SOURCES})

# Optional: extra warnings
target_compile_options(AdventOfCode2025 PRIVATE -Wall -Wextra -Wpedantic)
