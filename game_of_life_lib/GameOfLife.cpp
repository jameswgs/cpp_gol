//
// Created by James Shephard on 25/04/2017.
//

#include <vector>
#include <map>
#include "GameOfLife.h"

std::map<Cell, int> getLiveCellsNeighboursWithLiveNeighbourCount(const std::set<Cell> &liveCells);

bool contains(std::set<Cell> &liveCells, const Cell &cell);

std::set<Cell> evolveGameOfLife(std::set<Cell> liveCells) {

    std::map<Cell, int> neighbourCounts = getLiveCellsNeighboursWithLiveNeighbourCount(liveCells);

    std::set<Cell> nextGeneration;

    for (auto entry : neighbourCounts) {
        auto cell = entry.first;
        int count = entry.second;
        if( count == 3 || ( count == 2 && contains(liveCells, cell)) ) {
            nextGeneration.insert(cell);
        }
    }

    return nextGeneration;
}

bool contains(std::set<Cell> &liveCells, const Cell &cell) {
    bool contains = liveCells.find(cell) != liveCells.end();
    return contains;
}

std::map<Cell, int> getLiveCellsNeighboursWithLiveNeighbourCount(const std::set<Cell> &liveCells) {
    std::vector<Cell> allNeighbours;
    std::set<Cell> allNeighboursUnique;

    for (auto &&liveCell : liveCells) {
        auto neighbours = liveCell.getNeighbours();
        for (auto neighbour : neighbours) {
            allNeighbours.push_back(neighbour);
            allNeighboursUnique.insert(neighbour);
        }
    }

    std::map<Cell, int> neighbourCounts;

    for (auto &&unique : allNeighboursUnique) {
        int count = 0;
        for (auto neighbour : allNeighbours) {
            if(neighbour==unique) {
                count++;
            }
        }
        neighbourCounts[unique] = count;
    }
    return neighbourCounts;
}

