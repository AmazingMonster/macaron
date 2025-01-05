cmake_minimum_required(VERSION 3.28)

project(
    Macaron
    VERSION 1.0.0.0
    LANGUAGES CXX
)

# cache variables for installation destinations
include(GNUInstallDirs)

add_library(MacaronMacros INTERFACE)

set_target_properties(MacaronMacros PROPERTIES
    OUTPUT_NAME MacaronMacros
    EXPORT_NAME Macros
)

target_include_directories(MacaronMacros INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Test
if(CMAKE_SOURCE_DIR STREQUAL Macaron_SOURCE_DIR OR TEST_Macaron)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TestMacaron
    ${CMAKE_CURRENT_LIST_DIR}/tests/tests.cpp
)

target_include_directories(TestMacaron
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)

endif()


install(
    TARGETS MacaronMacros
    EXPORT Macaron
)

install(
    DIRECTORY macaron
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
    EXPORT Macaron
    FILE Macaron.cmake
    NAMESPACE Macaron::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/macaron
)

# include the package config helpers and generate the file below
include(CMakePackageConfigHelpers)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/MacaronConfig.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/macaron
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/MacaronConfig.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/macaron
)