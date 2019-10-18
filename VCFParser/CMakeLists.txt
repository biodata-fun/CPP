cmake_minimum_required(VERSION 3.14)
project(VCFParser)

set(CMAKE_CXX_STANDARD 17)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost REQUIRED COMPONENTS iostreams)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(app_demo src/main.cpp)
    target_link_libraries(app_demo ${Boost_LIBRARIES})
endif()

add_library(vcfparser
        include/VCFReader.h
        src/VCFReader.cpp)

target_include_directories(
        vcfparser
        PUBLIC
        "include"
)

target_link_libraries(app_demo vcfparser)
