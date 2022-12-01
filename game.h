#ifndef GAME_H
#define GAME_H


#include <string>
#include <iostream>

#include "board.h"
#include "subject.h"
#include "level.h"
#include "match.h"
#include "cell.h"

class Game: public subject{
    std::vector<std::vector<std::unique_ptr<Cell>>> board;
    Level *level;
    int height = 18, width = 11;
    int row, col;
    bool heavy, blind;
    void checkRows();
    void constructiveForce();
    void specialAction();
    void rotate();
    void left();
    void right();
    void drop();
    void down();
    

    public:
        Game(Board board, Level *level): board{board}, level{level}{};
        int levelFourCounter = 0;
        int numOfBlocksPlaced = 0;
        int currentLevel = 0;
        int score = 0;
        char getState(int row, int col);
        bool isHeavy();
        bool isBlind();
        void replaceCur(Block b);

}

#endif 
