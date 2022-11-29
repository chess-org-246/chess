#ifndef LEVELFOUR_H
#define LEVELFOUR_H

#include "abstractlevel.h"

class LevelFour : public AbstractLevel {
    bool isRandom;
    Block generateBlock();
};

#endif
