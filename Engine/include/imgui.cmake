cmake_minimum_required(VERSION 3.17)

project(imgui)

# Add sources
set(IMGUI_SOURCES
  imgui/imconfig.h
  imgui/imgui.cpp
  imgui/imgui.h
  imgui/imgui_demo.cpp
  imgui/imgui_draw.cpp
  imgui/imgui_internal.h
  imgui/imgui_widgets.cpp
  imgui/imstb_rectpack.h
  imgui/imstb_textedit.h
  imgui/imstb_truetype.h
  )

# Define library
add_library(${PROJECT_NAME} STATIC ${IMGUI_SOURCES})

target_compile_definitions(${PROJECT_NAME} PUBLIC IMGUI_API=${IMGUI_API})

# Set include directories
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/imgui)