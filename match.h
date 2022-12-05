#ifndef MATCH_H
#define MATCH_H

#include "game.h"
#include "eventmgr.h"
#include <iostream>
#include <sstream>
#include <utility>

class Match {
    int highScore;
    EventMgr em;
    Game game1;
    Game game2;

    public:
        Match(int p1Level, int p2Level);
        void playMatch();
};

#endif
