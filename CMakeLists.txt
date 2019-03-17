cmake_minimum_required(VERSION 3.12)
project(InteligentnaAnalizaDanych)

set(CMAKE_CXX_STANDARD 14)

include_directories(program/include)
include_directories(program/src)

add_executable(InteligentnaAnalizaDanych
        program/include/Perceptron.h
        program/src/main.cpp
        program/src/Perceptron.cpp program/include/Chodakowska.h program/src/Chodakowska.cpp program/src/Chodakowska.cpp program/include/Rysowanie.h program/src/Rysowanie.cpp)
