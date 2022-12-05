#ifndef MATCH_H
#define MATCH_H

#include "game.h"
#include "eventmgr.h"
#include "subject.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>

class Match : public Subject{
    int highScore;
    EventMgr em;
    Game game1;
    Game game2;

    public:
        Match(int p1Level, int p2Level);
        void restart();
        char getState(int row, int col) const override;
        char getPrevState(int row, int col) const;
        void playMatch();
        void printBoard(int playerNum);
};

#endif
