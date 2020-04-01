project(Foundation-Engine)

# Add sources
set (ENGINE_SOURCES
  src/engine.cpp
  src/engine.h
  )

# Define library
add_library(${PROJECT_NAME} ${ENGINE_SOURCES})
add_library(Foundation::Engine ALIAS ${PROJECT_NAME})

# Set include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)

# Language standard
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

# Build glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(include/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

# Link OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)