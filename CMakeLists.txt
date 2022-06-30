cmake_minimum_required(VERSION 3.22)
project(Cell)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cell main.cpp Cell.cpp Cell.h Point3D.cpp Point3D.h Petri.cpp Petri.h)
