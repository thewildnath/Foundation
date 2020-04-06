cmake_minimum_required(VERSION 3.17)

project(Foundation-Engine)

# Options
option(BUILD_SHARED_LIB "Build Foundation::Engine as a shared library" OFF)

# Add sources
set(ENGINE_SOURCES
  src/Foundation.h
  src/Foundation/Core.h
  src/Foundation/EntryPoint.h
  src/Foundation/Application.cpp
  src/Foundation/Application.h
  src/Foundation/Events/Event.h
  src/Foundation/Events/KeyEvent.h
  src/Foundation/Events/MouseEvent.h
  src/Foundation/Events/WindowEvents.h
  src/Foundation/Input/KeyCodes.h
  src/Foundation/Input/MouseCodes.h
  src/Foundation/Log.cpp
  src/Foundation/Log.h
  )

## Circumvent MSVC's need for __declspec(dllimport)
#set (CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
if(BUILD_SHARED_LIB)
  set(BUILD_MODE "SHARED")
else()
  set(BUILD_MODE "STATIC")
endif()

# Define library
add_library(${PROJECT_NAME} ${BUILD_MODE} ${ENGINE_SOURCES})
add_library(Foundation::Engine ALIAS ${PROJECT_NAME})

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify compile definitions
if(BUILD_SHARED_LIB)
  target_compile_definitions(${PROJECT_NAME} PUBLIC FND_BUILD_SHARED)
  target_compile_definitions(${PROJECT_NAME} PRIVATE FND_EXPORT)
endif()

# Set include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)

# Dependencies
set(SPDLOG_BUILD_SHARED ON FORCE)
add_subdirectory(include)

#Link libraries
target_link_libraries(${PROJECT_NAME} PUBLIC spdlog)