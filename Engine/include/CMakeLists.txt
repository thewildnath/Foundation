cmake_minimum_required(VERSION 3.17)

# Build spdlog
#set(SPDLOG_MASTER_PROJECT OFF CACHE BOOL "" FORCE)
set(SPDLOG_BUILD_SHARED ON FORCE)
#set(SPDLOG_ENABLE_PCH ON CACHE BOOL "" FORCE)
#set(SPDLOG_BUILD_EXAMPLES OFF CACHE BOOL "Build examples" FORCE)
#set(SPDLOG_BUILD_TESTING OFF CACHE BOOL "Build spdlog tests" FORCE)

add_subdirectory(spdlog)
set_target_properties(spdlog PROPERTIES FOLDER include)

# Build glfw
add_subdirectory(glfw)

# Build glad
add_subdirectory(glad)

#Build imgui
include(imgui.cmake)