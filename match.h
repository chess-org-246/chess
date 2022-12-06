#ifndef MATCH_H
#define MATCH_H

#include "game.h"
#include "eventmgr.h"
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>

class Match {
    int highScore;
    EventMgr em;
    std::unique_ptr<Game> game1;
    std::unique_ptr<Game> game2;

    public:
        Match(int _p1Level, std::string f1, int _p2Level, std::string f2);
        bool playMatch();
        void restart();
};

#endif
