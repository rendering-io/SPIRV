set(SOURCES Main.c++
            ModuleTests.c++)
add_executable(TestSPIRV ${SOURCES})
target_link_libraries(TestSPIRV PRIVATE ${GMOCK_LIBRARY} SPIRV)
