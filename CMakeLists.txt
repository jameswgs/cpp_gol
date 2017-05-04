cmake_minimum_required(VERSION 3.7)
project(game_of_life)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(game_of_life_run ${SOURCE_FILES})

include_directories(game_of_life_lib)

add_subdirectory(game_of_life_lib)
add_subdirectory(game_of_life_tests)

target_link_libraries(game_of_life_run game_of_life)