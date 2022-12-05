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

class LevelZero : public AbstractLevel {
    std::vector<char> sequence;
    int sequence_index;

    public:
        explicit LevelZero(std::string filename);
        std::unique_ptr<AbstractBlock> generateBlock(Board* board) override;
        void random() override;
        void noRandom(std::string f) override;
};

#endif
