cmake_minimum_required(VERSION 3.7)
project(game_of_life_lib)

set(CMAKE_CXX_STANDARD 11)

add_library(game_of_life_lib GameOfLife.cpp Cell.cpp Cell.h)