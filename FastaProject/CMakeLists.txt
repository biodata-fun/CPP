cmake_minimum_required(VERSION 3.14)
project(FastaProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(FastaProject src/Fasta.cpp src/FastaFile.cpp src/main.cpp src/FastaFile.h src/Fasta.h)

