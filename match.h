#ifndef MATCH_H
#define MATCH_H

#include "game.h"
#include <iostream>
#include <sstream>

class Match {
    int highScore
    Game game1;
    Game game2;
    Input input;

    public:
        Match(int p1Level, int p2Level);
        void playMatch();
};

#endif
