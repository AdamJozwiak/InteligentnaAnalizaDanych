cmake_minimum_required(VERSION 3.12)
project(Zad2)

set(CMAKE_CXX_STANDARD 14)

include_directories(program/include)
include_directories(program/src)

add_executable(Zad2
        program/src/main.cpp program/include/Plaszczyzna.h program/src/Plaszczyzna.cpp program/src/Neuron.cpp program/include/Neuron.h program/include/Punkt.h program/src/Punkt.cpp program/src/Rysowanie.cpp program/include/Rysowanie.h)