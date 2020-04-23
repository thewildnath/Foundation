cmake_minimum_required(VERSION 3.17)

project(glad)

# Add sources
set(GLAD_SOURCES
  src/glad.c
  include/glad/glad.h
  include/KHR/khrplatform.h
  )

# Define library
add_library(${PROJECT_NAME} STATIC ${GLAD_SOURCES})

# Set include directories
target_include_directories(${PROJECT_NAME} PUBLIC include/)
