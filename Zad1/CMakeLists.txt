cmake_minimum_required(VERSION 3.12)
project(Zad1)

set(CMAKE_CXX_STANDARD 14)

include_directories(program/include)
include_directories(program/src)

add_executable(Zad1
        program/src/main.cpp
        program/include/Neuron.h
        program/src/Neuron.cpp
        program/include/SiecNeuronowa.h
        program/src/SiecNeuronowa.cpp
        program/include/Warstwa.h
        program/src/Warstwa.cpp
        program/include/NeuronBezBiasu.h
        program/src/NeuronBezBiasu.cpp program/include/WarstwaBezBiasu.h program/src/WarstwaBezBiasu.cpp program/include/SiecBezBiasu.h program/src/SiecBezBiasu.cpp)