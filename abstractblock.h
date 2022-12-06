#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <memory>  
#include <unordered_set>
#include "board.h"
#include "masks.h"

// Abstract block class to be inherited from by each block
//   Contains block-specific methods, like moving and collision testing.
class AbstractBlock {
    protected:
        static unsigned long nextId;
        // outline of the current rotation of the block
        std::vector<std::vector<std::vector<int>>> mask; 

        // current board
        Board * board;

        // current orientation
        int currOrientation;

        // current position
        int t;
        int l;

        // info about the block
        char blockType;
        int blockLevel;
        unsigned long blockId;

    public:
        // dtor
        virtual ~AbstractBlock();

        // ctor
        AbstractBlock(Board * board, int _blockLevel): 
            board{board}, currOrientation{0}, t{0}, l{0}, blockLevel{_blockLevel}, blockId{nextId++} {
            };

        // move the block to a position
        void updateBoard(int t, int l);

        // undo a move
        void resetBoard(int t, int l, int orientation);

        // clears a generated block from its initial position
        void removeBlock(int t, int l);

        // collision checker
        bool testCollisions(int t, int l, int prevmask);

        // move block horizontally
        void left();
        void right();

        // rotate block
        void rotate(bool ccw);

        // move vertically
        void down();
        void drop();

        // checks if block is still alive
        bool checkCells(std::unordered_set<unsigned long> idSet);

        // getters
        int getT();
        int getL();
        int getBlockLevel();
        char getBlockType();
        unsigned long getBlockId();
};

#endif
