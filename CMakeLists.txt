cmake_minimum_required(VERSION 3.12)
project(layoutplanks)

set(CMAKE_CXX_STANDARD 14)

add_executable(layoutplanks main.cpp Rectangle.cpp Rectangle.h PatchWork.cpp PatchWork.h Join.cpp Join.h LayoutException.cpp LayoutException.h)