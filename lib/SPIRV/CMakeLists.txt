set(SOURCES Function.c++
            Module.c++)
add_library(SPIRV ${SOURCES})
target_include_directories(SPIRV PUBLIC ${CMAKE_SOURCE_DIR}/include)