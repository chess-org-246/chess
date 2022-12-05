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

class Game: public Subject{
    int height = 18, width = 11;
    Board board;
    std::vector<std::vector<char>>prevBoard = std::vector<std::vector<char>>(height, std::vector<char>(width, '.')); /* 18 rows * 11 cols */
    std::unique_ptr<AbstractLevel> level;
    int row, col;
    bool heavy, blind;
    std::unique_ptr<AbstractBlock> currBlock;
    
    public:
        int levelFourCounter = 0;
        int numOfBlocksPlaced = 0;
        int currentLevel = 0;
        int score = 0;

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
        void copyBoard();
        char getState(int row, int col) const override;
        char getPrevState(int row, int col) const;
        bool isHeavy();
        bool isBlind();
        void replaceCur(AbstractBlock* b);
};

#endif 
