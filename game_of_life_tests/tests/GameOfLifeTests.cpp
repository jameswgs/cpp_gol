
#include <GameOfLife.h>
#include <Cell.h>
#include "gtest/gtest.h"

bool cellSetContains(std::set<Cell> set, Cell);

TEST(basic_check, test_eq) {
    EXPECT_EQ(1, 1);
}

TEST(game_of_life, test_a_lone_cell_dies) {
    Cell cellAt11(1, 1);
    std::set<Cell> liveCells{cellAt11};
    std::set<Cell> nextGeneration = evolveGameOfLife(liveCells);
    EXPECT_FALSE(cellSetContains(nextGeneration, cellAt11));
}

TEST(game_of_life, test_a_cell_with_two_neighbours_survives) {
    Cell cellAt11(1, 1);
    std::set<Cell> liveCells{cellAt11, Cell(0,0), Cell(0,1)};
    std::set<Cell> nextGeneration = evolveGameOfLife(liveCells);
    EXPECT_TRUE(cellSetContains(nextGeneration, cellAt11));
}

TEST(game_of_life, test_a_dead_cell_with_three_neighbours_becomes_alive) {
    std::set<Cell> liveCells{Cell(0,0), Cell(0,1), Cell(0,2)};
    std::set<Cell> nextGeneration = evolveGameOfLife(liveCells);
    EXPECT_TRUE(cellSetContains(nextGeneration, Cell(1,1)));
}

bool cellSetContains(std::set<Cell> cellSet, Cell cell) {
    return cellSet.find(cell) != cellSet.end();
}

