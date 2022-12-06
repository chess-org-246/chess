#ifndef GAME_H
#define GAME_H


#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <utility>

#include "board.h"
#include "abstractblock.h"
#include "specialblock.h"
#include "subject.h"
#include "abstractlevel.h"
#include "cell.h"
#include "levelzero.h"
#include "levelone.h"
#include "leveltwo.h"
#include "levelthree.h"
#include "levelfour.h"

class Game/*: public Subject*/{
    char nextBlock = '!';
    int height = 18, width = 11;
    Board board;
    std::vector<std::vector<char>>prevBoard = std::vector<std::vector<char>>(height, std::vector<char>(width, '.')); /* 18 rows * 11 cols */
    std::unique_ptr<AbstractLevel> level;
    int row, col;
    int levelFourCounter = 0;
    int numOfBlocksPlaced = 0;
    int currentLevel = 0;
    int score = 0;
    bool specialActionAvailable = false;
    bool heavy = false;
    std::vector<std::unique_ptr<AbstractBlock>> blocks;
    AbstractBlock * currBlock;
    
    public:
        Game();
        Game(int curLevel, std::string filename = "");
        // void printBoard();
        void checkRows();
        void genBlock();
        void constructiveForce();
        void specialAction();
        void rotate();
        void left();
        void right();
        void drop();
        void down();
        void rotateCW();
        void rotateCCW();

        void random();
        void noRandom(std::string f);
        void levelUp();
        void levelDown(std::string f);
        bool levelHeavy();
        bool specialHeavy();

        void makeBlind();
        void makeHeavy();
        
        void copyBoard();
        char getState(int row, int col) const;
        char getPrevState(int row, int col) const;

        int getScore();
        int getLevel();
        std::vector<std::vector<char>> getNext();
        bool getSpecial();
        void setSpecial(bool b);

        bool isHeavy();
        void replaceI();
        void replaceJ();
        void replaceL();
        void replaceO();
        void replaceS();
        void replaceT();
        void replaceZ(); 
};

#endif 
