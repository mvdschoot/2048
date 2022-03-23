cmake_minimum_required(VERSION 2.4)

project(2048)

set(SRC_DIRECTORY "src")

include_directories(SRC_DIRECTORY)
add_executable(2048 src/Main.cpp src/Input.cpp src/HelperFunctions.cpp src/Board.cpp src/Application.cpp)