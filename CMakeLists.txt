# Set the required CMake version.
cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

# Build external libraries.
add_subdirectory(ext)

# Build unit tests.
add_subdirectory(test)
