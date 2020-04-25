cmake_minimum_required(VERSION 3.17)

project(Foundation-Engine)

# Options
option(FND_BUILD_SHARED_LIB "Build Foundation::Engine as a shared library" OFF)
option(FND_BUILD_DEBUG "Keep debug preprocessor directives in code" OFF)

if(FND_BUILD_SHARED_LIB)
  set(BUILD_MODE "SHARED")
else()
  set(BUILD_MODE "STATIC")
endif()

# Add sources
set(ENGINE_SOURCES
  src/Foundation.h
  src/Foundation/Core.h
  src/Foundation/fndpch.cpp
  src/Foundation/fndpch.h
  src/Foundation/EntryPoint.h
  src/Foundation/Core/Application.cpp
  src/Foundation/Core/Application.h
  src/Foundation/Core/Layer.cpp
  src/Foundation/Core/Layer.h
  src/Foundation/Core/LayerManager.cpp
  src/Foundation/Core/LayerManager.h
  src/Foundation/Core/Log.cpp
  src/Foundation/Core/Log.h
  src/Foundation/Core/Window.cpp
  src/Foundation/Core/Window.h
  src/Foundation/Events/Event.h
  src/Foundation/Events/KeyEvent.h
  src/Foundation/Events/MouseEvent.h
  src/Foundation/Events/WindowEvents.h
  src/Foundation/ImGui/ImGuiLayer.cpp
  src/Foundation/ImGui/ImGuiLayer.h
  src/Foundation/Input/KeyCodes.h
  src/Foundation/Input/MouseCodes.h
  src/Foundation/Utils/Singleton.h
  src/Platform/ImGui/imgui_impl_glfw.cpp
  src/Platform/ImGui/imgui_impl_glfw.h
  src/Platform/ImGui/imgui_impl_opengl3.cpp
  src/Platform/ImGui/imgui_impl_opengl3.h
  src/Platform/Windows/WindowsWindow.cpp
  src/Platform/Windows/WindowsWindow.h
  )

# Define library
add_library(${PROJECT_NAME} ${BUILD_MODE} ${ENGINE_SOURCES})
add_library(Foundation::Engine ALIAS ${PROJECT_NAME})

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify compile definitions
target_compile_definitions(${PROJECT_NAME} PRIVATE FND_BUILD_ENGINE)

if(FND_BUILD_SHARED_LIB)
  target_compile_definitions(${PROJECT_NAME} PUBLIC FND_BUILD_SHARED)
endif()

if(FND_BUILD_DEBUG)
  target_compile_definitions(${PROJECT_NAME} PUBLIC FND_BUILD_DEBUG)
endif()

target_compile_definitions(${PROJECT_NAME} PUBLIC GLFW_INCLUDE_NONE)

# Set include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)

# Specify precompiled headers
target_precompile_headers(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src/Foundation/fndpch.h)

# Dependencies
set(SPDLOG_BUILD_SHARED ON FORCE)
add_subdirectory(include)

#Link libraries
target_link_libraries(${PROJECT_NAME}
  PUBLIC spdlog
  PRIVATE glfw glad imgui)