#ifndef MATCH_H
#define MATCH_H

#include "game.h"
#include "input.h"
#include <iostream>
#include <stringstream>

class Match {
    int high_score_1;
    int high_score_2;
    Game game_1;
    Game game_2;
    Input input;

    public:
        Match();
        void playMatch();
};

#endif
