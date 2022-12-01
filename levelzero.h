#ifndef LEVELZERO_H
#define LEVELZERO_H

#include "abstractlevel.h"
#include <vector>
#include <string>
#include <fstream>

class LevelZero : public AbstractLevel {
    vector<char> sequence;
    int sequence_index;

    public:
        explicit LevelZero(std::string filename);
        Block generateBlock();
};

#endif
