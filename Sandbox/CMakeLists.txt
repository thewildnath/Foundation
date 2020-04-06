cmake_minimum_required(VERSION 3.17)

project(Foundation-Sandbox)

# Add sources
set(SANDBOX_SOURCES
  src/Sandbox.cpp
  )

# Define executable
add_executable(${PROJECT_NAME} ${SANDBOX_SOURCES})

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)

# Link libraries
target_link_libraries(${PROJECT_NAME} PUBLIC Foundation::Engine)