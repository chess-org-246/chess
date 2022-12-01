#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <memory>  /* shared_ptr */
#include "board.h"

class AbstractBlock {
    protected:
    std::vector<std::vector<Cell*>> blockCells;
    std::vector<std::vector<std::vector<int>>> mask; /* 2d vector of cell ptrs, 4x4 */
    Board * board;
    int currOrientation;
    public:
        AbstractBlock(Board * board) : board{board}, currOrientation{0} {};
        void left();
        void right();
        void rotate(bool ccw);
        void down();
        void drop();
};

#endif
