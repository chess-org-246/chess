#ifndef LEVELZERO_H
#define LEVELZERO_H

#include "abstractlevel.h"
#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"

//inhereits from abstractlevel
class LevelZero : public AbstractLevel {
    std::string sequence; 
    int sequence_index = 0;

    public:
        explicit LevelZero(std::string filename); //explicit for one parameter constructor
        std::unique_ptr<AbstractBlock> generateBlock(Board* board, char block) override; //generate block function
        char randomizeBlock() override; 
        void random() override;
        void noRandom(std::string f) override;
};

#endif
