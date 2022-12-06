#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include "cell.h"
#include "window.h"
#include <iostream>


// The board for the game
class Board {
    public:
        // board of cells
        std::vector<std::vector<std::unique_ptr<Cell>>> board; /* 18 rows * 11 cols */

        // ctor
        Board();
};

#endif
