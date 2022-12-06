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


// Class for each instance of a player's game
//   Handles game-related methods, like creating blocks, applying effects, and implementing
//   interpreter commands
class Game {
    // buffer for the next block 
    char nextBlockChar = '!';
    
    // values for the board
    int height = 18, width = 11;

    // owns a board
    Board board;

    // owns a level
    std::unique_ptr<AbstractLevel> level;

    // counter for constructive force
    int levelFourCounter = 0;

    // current level
    int currentLevel = 0;

    // score
    int score = 0;

    // flags for special actions
    bool specialActionAvailable = false;
    bool heavy = false;
    bool blind = false;

    // vector to store blocks 
    //   used to award points when blocks are cleared  
    std::vector<std::unique_ptr<AbstractBlock>> blocks;

    // current block pointer
    AbstractBlock * currBlock;
    
    public:
    // ctors
        Game();
        Game(int curLevel, std::string filename = "");

        // to check if rows can be cleared, and apply score
        void checkRows();

        // create a new block
        void genBlock();

        // spawn a constructive force block
        void constructiveForce();

        // trigger a special action
        void specialAction();

        // manipulate the current block
        void rotate();
        void left();
        void right();
        void drop();
        void down();
        void rotateCW();
        void rotateCCW();

        // Adjust the current level
        void random();
        void noRandom(std::string f);
        void levelUp();
        void levelDown(std::string f);

        // special actions
        bool levelHeavy();
        bool specialHeavy();
        void makeBlind();
        void unblind();
        void makeHeavy();
        
        // get state (for observer)
        char getState(int row, int col) const;

        // getters
        int getScore();
        int getLevel();
        char nextBlock();
        bool getSpecial();
        bool getBlind();
        void setSpecial(bool b);
        bool isHeavy();
        bool isBlind();

        // setters 
        void replaceI();
        void replaceJ();
        void replaceL();
        void replaceO();
        void replaceS();
        void replaceT();
        void replaceZ(); 
};

#endif 
