#ifndef LEVELTHREE_H
#define LEVELTHREE_H

#include "abstractlevel.h"
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <memory>
#include "iblock.h"
#include "jblock.h"
#include "lblock.h"
#include "oblock.h"
#include "sblock.h"
#include "tblock.h"
#include "zblock.h"

class LevelThree : public AbstractLevel {
    bool isRandom;
    vector<char> sequence;
    int sequence_index;
    public: 
        LevelThree();
        void random();
        void noRandom(std::string filename);
        Block generateBlock(Board* board);
};

#endif
