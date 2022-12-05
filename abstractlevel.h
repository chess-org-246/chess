#ifndef ABSTRACTLEVEL_H
#define ABSTRACTLEVEL_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "error.h"
class Board;
class AbstractBlock;

class AbstractLevel {
    public:
        virtual std::unique_ptr<AbstractBlock> generateBlock(Board * board) = 0;
        virtual void random() = 0;
        virtual void noRandom(std::string f) = 0;
};

#endif
