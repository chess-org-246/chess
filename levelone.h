#ifndef LEVELONE_H
#define LEVELONE_H

#include "abstractlevel.h"
#include <cstdlib> 
#include <memory>
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"

class Board;

class LevelOne : public AbstractLevel {
    public:
        Block* generateBlock(Board* board);
};

#endif
