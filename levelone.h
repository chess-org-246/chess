#ifndef LEVELONE_H
#define LEVELONE_H

#include "abstractlevel.h"
#include <random> 

class LevelOne : public AbstractLevel {
    int seed;

    public:
        explicit LevelOne(int _seed = 0);
        Block generateBlock();
};

#endif
