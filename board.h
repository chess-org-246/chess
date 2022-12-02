#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include "cell.h"
#include <iostream>

class Board {
    public:
    std::vector<std::vector<std::unique_ptr<Cell>>> board; /* 18 rows * 11 cols */
    Board();
    void printBoard();
};

#endif
