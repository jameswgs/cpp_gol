//
// Created by James Shephard on 25/04/2017.
//

#include <tuple>
#include <set>
#include "Cell.h"

Cell::Cell(int x, int y) : x(x), y(y) {
}

Cell::Cell(const Cell &cell) : x(cell.x), y(cell.y) {
}

bool Cell::operator==(const Cell &cell) {
    return this->x == cell.x && this->y == cell.y;
}

int Cell::cmp(const Cell &cell) const {
    int xcmp = this->x - cell.x;
    return xcmp != 0 ? xcmp : this->y - cell.y;
}

const std::set<Cell> Cell::getNeighbours() const {
    std::set<Cell> neighbours;
    neighbours.insert(Cell(x - 1, y - 1));
    neighbours.insert(Cell(x - 1, y    ));
    neighbours.insert(Cell(x - 1, y + 1));
    neighbours.insert(Cell(x    , y - 1));
    neighbours.insert(Cell(x    , y + 1));
    neighbours.insert(Cell(x + 1, y - 1));
    neighbours.insert(Cell(x + 1, y    ));
    neighbours.insert(Cell(x + 1, y + 1));
    return neighbours;
}

Cell::Cell() : x(0), y(0) {
}

bool operator<(const Cell &cell0, const Cell &cell1) {
    return cell0.cmp(cell1) < 0;
}

