cmake_minimum_required(VERSION 3.26)
project(OOPCES_Vector)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(OOPCES_Vector
        main.cpp
        MyVector.h)
