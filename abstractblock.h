#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <memory>  /* shared_ptr */
#include "board.h"

class AbstractBlock {
    protected:
        //std::vector<std::vector<Cell*>> blockCells;
        std::vector<std::vector<std::vector<int>>> mask; 
        Board * board;
        int currOrientation;
        int t;
        int l;
        char blockType;
        int blockLevel;
    public:
        virtual ~AbstractBlock();

        AbstractBlock(Board * board, int _blockLevel): 
            board{board}, currOrientation{0}, t{0}, l{0}, blockLevel{_blockLevel} {};
        void updateBoard(int t, int l);
        void resetBoard(int t, int l, int orientation);
        bool testCollisions(int t, int l, int prevmask);
        void left();
        void right();
        void rotate(bool ccw);
        void down();
        void drop();
        bool checkCells();

        int getT();
        int getL();
        int getBlockLevel();
        char getBlockType();
};

#endif
