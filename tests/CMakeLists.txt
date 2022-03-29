cmake_minimum_required(VERSION 2.4)

project(2048)
set(CMAKE_BUILD_TYPE Debug)

## Include FTXUI
include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v2.0.0
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()


#include_directories("libs/Graphics")

add_executable(2048 main.cpp)

#target_link_libraries(2048 PUBLIC Graphics)


target_link_libraries(2048
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)