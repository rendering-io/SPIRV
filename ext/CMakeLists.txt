# Include ExternalProject module.
include(ExternalProject)

# Declare an external project for building GoogleTest.
ExternalProject_Add(GoogleTest
  GIT_REPOSITORY https://github.com/google/googletest.git
  INSTALL_COMMAND "")

# Get the include directories for GoogleTest and GoogleMock.
ExternalProject_Get_Property(GoogleTest source_dir)
set(GTEST_INCLUDE_DIR ${source_dir}/googletest/include)
set(GMOCK_INCLUDE_DIR ${source_dir}/googlemock/include)

# Build libraries.
ExternalProject_Get_Property(GoogleTest binary_dir)
set(GTEST_LIBRARY_PATH ${binary_dir}/googlemock/gtest/${CMAKE_FIND_LIBRARY_PREFIXES}gtest.a)
set(GMOCK_LIBRARY_PATH ${binary_dir}/googlemock/${CMAKE_FIND_LIBRARY_PREFIXES}gmock.a)
set(GTEST_LIBRARY gtest)
set(GMOCK_LIBRARY gmock)

add_library(${GTEST_LIBRARY} STATIC IMPORTED GLOBAL)
set_property(TARGET ${GTEST_LIBRARY} PROPERTY IMPORTED_LOCATION 
             ${GTEST_LIBRARY_PATH})
add_library(${GMOCK_LIBRARY} STATIC IMPORTED GLOBAL)
set_property(TARGET ${GMOCK_LIBRARY} PROPERTY IMPORTED_LOCATION
             ${GMOCK_LIBRARY_PATH})

# Set include directories property for libraries.
set_target_properties(${GTEST_LIBRARY} PROPERTIES 
                      INTERFACE_INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIR})
set_target_properties(${GMOCK_LIBRARY} PROPERTIES 
                      INTERFACE_INCLUDE_DIRECTORIES ${GMOCK_INCLUDE_DIR})

# Set library dependencies.
target_link_libraries(${GTEST_LIBRARY} INTERFACE pthread)
target_link_libraries(${GMOCK_LIBRARY} INTERFACE ${GTEST_LIBRARY})

add_dependencies(${GTEST_LIBRARY} GoogleTest)
add_dependencies(${GMOCK_LIBRARY} GoogleTest)

set(GTEST_LIBRARY gtest PARENT_SCOPE)
set(GMOCK_LIBRARY gmock PARENT_SCOPE)
