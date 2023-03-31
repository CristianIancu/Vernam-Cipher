cmake_minimum_required(VERSION 3.10)

project(vernam)

# Set the executable output directory to the root directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Include the src directory
add_subdirectory(src)