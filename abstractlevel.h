#ifndef ABSTRACTLEVEL_H
#define ABSTRACTLEVEL_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "error.h"

// forward declares
class Board; 
class AbstractBlock;

// Abstract level class
//   Implements Level-specific methods (generate block)
class AbstractLevel {
    public:
        // places the block onto the board
        virtual std::unique_ptr<AbstractBlock> generateBlock(Board * board, char Block) = 0;

        // decides which block is next (random or from file)
        virtual char randomizeBlock() = 0;

        // toggle between random and no-random modes
        virtual void random() = 0;
        virtual void noRandom(std::string f) = 0;
};

#endif
