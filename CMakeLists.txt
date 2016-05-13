# Set the required CMake version.
cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

add_compile_options(-std=c++11)

# Build external libraries.
add_subdirectory(ext)

# Build SPIRV library.
add_subdirectory(lib)

# Build unit tests.
add_subdirectory(test)
