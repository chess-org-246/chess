#ifndef MATCH_H
#define MATCH_H

#include "game.h"
#include "eventmgr.h"
#include <memory>
#include "subject.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>

class Match : public Subject{
    int highScore;

    EventMgr em;
    std::unique_ptr<Game> game1;
    std::unique_ptr<Game> game2;

    public:
        Match(int _p1Level, std::string f1, int _p2Level, std::string f2);
        void restart();
        char getState(int row, int col, int playerNum) const override;
        int getLevel(int playerNum);
        int getScore(int playerNum);
        char getPrevState(int row, int col, int playerNum) const;
        std::vector<std::vector<char>> getNext(int playerNum);
        bool playMatch();
        void printBoard();
};

#endif
