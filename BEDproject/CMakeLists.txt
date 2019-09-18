cmake_minimum_required(VERSION 3.14)
project(BEDfile)

set(CMAKE_CXX_STANDARD 14)

add_executable(BEDfile main.cpp src/BEDfile.h src/BEDfile.cpp)