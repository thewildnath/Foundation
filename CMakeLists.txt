cmake_minimum_required(VERSION 3.14)

project(Foundation)

# Options
option(BUILD_SANDBOX "Build sandbox application" ON)

# Set output directories
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Foundation-Engine
add_subdirectory(Engine)

# Sandbox
if(BUILD_SANDBOX)
  add_subdirectory(Sandbox)
endif()