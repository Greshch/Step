cmake_minimum_required(VERSION 3.19)

project(step)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)

add_executable(step src/main.cpp  src/guitar.cpp src/valisa.cpp src/panzer.cpp src/window.cpp src/laptop.cpp)