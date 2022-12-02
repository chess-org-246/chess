#ifndef GAME_H
#define GAME_H


#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <utility>

#include "board.h"
#include "abstractblock.h"
#include "subject.h"
#include "abstractlevel.h"
#include "cell.h"
//#include "levelzero.h"
#include "levelone.h"
// #include "leveltwo.h"
// #include "levelthree.h"
// #include "levelfour.h"

class Game/*: public Subject*/{
    Board board;
    std::unique_ptr<AbstractLevel> level;
    int height = 18, width = 11;
    int row, col;
    int levelFourCounter = 0;
    int numOfBlocksPlaced = 0;
    int currentLevel = 0;
    int score = 0;
    bool heavy, blind;
    std::vector<std::unique_ptr<AbstractBlock>> blocks;
    
    public:
        Game(int curLevel, std::string filename = "");
        void printBoard();
        void checkRows();
        void genBlock();
        void constructiveForce();
        void specialAction();
        void rotate();
        void left();
        void right();
        void drop();
        void down();
        void rotate(bool ccw);
        char getState(int row, int col);
        bool isHeavy();
        bool isBlind();
        void replaceCur(AbstractBlock* b);
};

#endif 
