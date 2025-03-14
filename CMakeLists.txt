cmake_minimum_required(VERSION 3.10)
project(StreamDeckApp)

set(CMAKE_CXX_STANDARD 17)

add_executable(streamdeck src/main.cpp src/backend.cpp src/gui.cpp)
include_directories(include)
