#ifndef MATCH_H
#define MATCH_H

#include "game.h"
#include "eventmgr.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>

class Match {
    int highScore;
    EventMgr em;
    Game game1;
    Game game2;

    public:
        Match(int _p1Level, int _p2Level);
        void playMatch();
        void restart();
};

#endif
