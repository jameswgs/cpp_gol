include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runGameOfLifeTests GameOfLifeTests.cpp)

target_link_libraries(runGameOfLifeTests gtest gtest_main)
target_link_libraries(runGameOfLifeTests game_of_life_lib)

