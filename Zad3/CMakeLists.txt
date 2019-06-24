cmake_minimum_required(VERSION 3.12)
project(Zad3)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(src)

add_executable(Zad3 src/main.cpp include/NeuronRad.h src/NeuronRad.cpp include/WarstwaRad.h src/WarstwaRad.cpp src/klasaSortNeur.cpp include/klasaSortNeur.h include/NeuronLin.h src/NeuronLin.cpp include/WarstwaLin.h src/WarstwaLin.cpp)