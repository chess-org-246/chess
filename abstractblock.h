#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <memory> /* shared_ptr */

class AbstractBlock {
    std::vector<std::vector<shared_ptr<Cell>>> blockCells; /* 2d vector of cell ptrs, 4x4 */

    public:
        void left();
        void right();
        void rotate(bool ccw) = 0;
        void down();
        void drop();
};

#endif
