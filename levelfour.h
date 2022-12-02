#ifndef LEVELFOUR_H
#define LEVELFOUR_H

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

class LevelFour : public AbstractLevel {
    bool isRandom;
    std::vector<char> sequence;
    int sequence_index;

    public:
        LevelFour();
        void random();
        void noRandom(std::string filename);
        AbstractBlock* generateBlock(Board* board);
};

#endif
