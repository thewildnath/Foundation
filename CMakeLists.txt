cmake_minimum_required(VERSION 3.14)

project(Foundation)

# Options
option(BUILD_SANDBOX "Build sandbox application" ON)

# Foundation-Engine
add_subdirectory(Engine)

# Sandbox
if(BUILD_SANDBOX)
  add_subdirectory(Sandbox)
endif()