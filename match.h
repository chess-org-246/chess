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

    std::string file1;
    std::string file2;

    public:
        Match(int _p1Level, std::string f1, int _p2Level, std::string f2);
        void restart();
        char getState(int row, int col, int playerNum) const override; //returns the state for a specific player at a specific position
        int getLevel(int playerNum); //returns the level of the specific player
        int getScore(int playerNum); //returns the score of the specific player
        char nextBlock(int playerNum); //returns the next block of the specific player
        bool playMatch(); 
        void printBoard(); //notifys the observers
        int getHighScore();
};

#endif
