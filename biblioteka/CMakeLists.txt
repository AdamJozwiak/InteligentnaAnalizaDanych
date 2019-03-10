cmake_minimum_required(VERSION 3.4)
project(Biblioteka)

set(SOURCE_FILES
		src/Punkt.cpp
		)

add_library(Biblioteka ${SOURCE_FILES})

target_include_directories(Biblioteka PUBLIC include)