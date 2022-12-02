#ifndef ABSTRACTLEVEL_H
#define ABSTRACTLEVEL_H

#include <string>
#include <vector>
#include <memory>
#include "error.h"
class Board;
class AbstractBlock;

class AbstractLevel {
    public:
        virtual std::unique_ptr<AbstractBlock> generateBlock(Board * board) = 0;
};

#endif
