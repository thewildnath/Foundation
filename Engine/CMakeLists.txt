project(Foundation-Engine)

# Add sources
set (ENGINE_SOURCES
  src/engine/engine.cpp
  src/engine/engine.h
  src/engine/Application.cpp
  src/engine/Application.h
  src/Foundation.h
  src/engine/Core.h
  src/engine/EntryPoint.h)

# Define library
add_library(${PROJECT_NAME} SHARED ${ENGINE_SOURCES})
add_library(Foundation::Engine ALIAS ${PROJECT_NAME})

# Set include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)

# Compiler options
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

## Build glfw
#set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
#set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
#
#add_subdirectory(include/glfw-3.3.2)
#target_link_libraries(${PROJECT_NAME} glfw)
#
## Link OpenGL
#find_package(OpenGL REQUIRED)
#target_link_libraries(${PROJECT_NAME} OpenGL::GL)