cmake_minimum_required(VERSION 3.17)

project(Foundation)

# Options
set(FND_BUILD_SHARED_LIB ON)
option(BUILD_SANDBOX "Build sandbox application" ON)

if (CMAKE_BUILD_TYPE MATCHES Debug)
  message("CMAKE IN DEBUG MODE")
  set(FND_BUILD_DEBUG ON)
elseif(CMAKE_BUILD_TYPE MATCHES Release)
  message("CMAKE IN RELEASE MODE")
endif ()

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/output/debug/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/output/release/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/output/debug/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/output/release/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/output/debug/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/output/release/lib)

# Foundation Engine
add_subdirectory(Engine)

# Sandbox
if(BUILD_SANDBOX)
  add_subdirectory(Sandbox)
endif()