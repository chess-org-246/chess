#ifndef LEVELTWO_H
#define LEVELTWO_H

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

class LevelTwo : public AbstractLevel {
    public:
        std::unique_ptr<AbstractBlock> generateBlock(Board* board, char block); //generate block, returns an abstract block pointer
        char randomizeBlock() override;
        void random() override;
        void noRandom(std::string f) override;
};

#endif
