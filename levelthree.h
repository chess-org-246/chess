#ifndef LEVELTHREE_H
#define LEVELTHREE_H

#include "abstractlevel.h"

class LevelThree : public AbstractLevel {
    bool isRandom;
    Block generateBlock();
};

#endif
