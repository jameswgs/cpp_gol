//
// Created by James Shephard on 25/04/2017.
//

#ifndef GAME_OF_LIFE_CELL_H
#define GAME_OF_LIFE_CELL_H


class Cell {

public:

    int x, y;

public:

    Cell();

    Cell(const Cell& cell);

    Cell(int x, int y);

    int cmp(const Cell& cell) const;

    bool operator==(const Cell& cell);

    const std::set<Cell> getNeighbours() const;
};

bool operator<(const Cell& cell0, const Cell& cell1);


#endif //GAME_OF_LIFE_CELL_H
