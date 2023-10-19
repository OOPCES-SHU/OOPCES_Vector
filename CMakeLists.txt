cmake_minimum_required(VERSION 3.26)
project(OOPCES_Vector)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(OOPCES_Vector
        main.cpp
        MyVector.h
        Test.cpp
        Menu.cpp
)
