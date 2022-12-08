#include "game.h"

// ctor
Game::Game(int curLevel, bool _gameIsP1, std::string filename):
    currentLevel{curLevel} , currBlock{nullptr}, gameIsP1{_gameIsP1} {
        filename = filename;
        nextBlockChar = '!';
        if (curLevel == 0) {
            level = std::make_unique<LevelZero>(filename);
        } else if (curLevel == 1) {
            level = std::make_unique<LevelOne>();
        } else if (curLevel == 2) {
            level = std::make_unique<LevelTwo>();
        } else if (curLevel == 3) {
            level = std::make_unique<LevelThree>();
        } else if (curLevel == 4) {
            level = std::make_unique<LevelFour>();
        } else {
            throw ControlOutOfRange{};
        }

}

// getters
char Game::nextBlock(){
    return nextBlockChar;
}
char Game::getState(int row, int col) const{
    return board.board[row][col]->getHidden() ? '?' : board.board[row][col]->getChar();
}

int Game::getScore() {
    return score;
}

int Game::getLevel() {
    return currentLevel;
}

bool Game::getSpecial() {
    return specialActionAvailable;
}

bool Game::getBlind() {
    return blind;
}

bool Game::getPlayerTurn(){
    return gameIsP1;
}

// setter
void Game::setSpecial(bool b) {
    specialActionAvailable = b;
}

// generates a new block, updates current and nexts
void Game::genBlock() {
    // generate the next block
    try {
        char first = level->randomizeBlock();

        // if we haven't generated a block before, we have to generate 2 
        if (nextBlockChar == '!') {
            // make the next one 
            nextBlockChar = level->randomizeBlock();
            // put the first block into the board
            blocks.insert(blocks.begin(), level->generateBlock(&board, first));
        } else {
            // otherwise, just put the previously generated next block into the board
            blocks.insert(blocks.begin(), level->generateBlock(&board, nextBlockChar));
        }
        // update the next block with the newly generated one
        nextBlockChar = first;
        // update current block pointer
        currBlock = blocks[0].get();
    } catch (NoSpaceForBlock e) {
        e.setPlayer1(gameIsP1);
        throw e;
    }
    
}

void Game::checkRows() {
    int numOfRowsCleared = 0; // counter

    // loop over height
    for(int i = 0;i < height; ++i){
        bool fullRow = true;
        for(int j = 0; j < width;j++){
            // if there's ever an unoccupied cell ('.'), then it's not complete
            if(board.board[i][j]->getChar() == '.'){
                fullRow = false; // so change the flag
            }
        }
        if(fullRow) { // if we have a full row
            // erase the full row
            board.board.erase(board.board.begin() + i);
            // create a new row
            std::vector<std::unique_ptr<Cell>> vec;
            for (int k = 0; k < width; ++k) {
                // fill the new row with empty cells 
                std::unique_ptr<Cell> p {new Cell('.')};
                vec.push_back(std::move(p));
            }
            // and push it into the board
            board.board.insert(board.board.begin(), std::move(vec));
            numOfRowsCleared++;
        }
    }

    std::unordered_set<unsigned long> idSet;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            idSet.insert(board.board[i][j]->getBlockId());
        }
    }
    

    // behaviour dependent on # of rows cleared
    if (numOfRowsCleared == 0) {
        levelFourCounter++; // constructive force
    } else if(numOfRowsCleared == 1) { // one block cleared, just add score
        score += (currentLevel + 1) * (currentLevel + 1);
        levelFourCounter = 0; // reset force counter
    } else if(numOfRowsCleared >= 2){
        levelFourCounter = 0; // reset force counter
        score += (currentLevel + numOfRowsCleared) * (currentLevel + numOfRowsCleared);
        specialActionAvailable = true; // enable special action
    }
    // check if any blocks have entirely been deleted
    for (auto it = blocks.begin(); it != blocks.end(); ++it) {
        // if we don't find any remaining cells
        if (!((*it)->checkCells(idSet))) {
            // add to the score
            score += (1 + (*it)->getBlockLevel()) * (1 + (*it)->getBlockLevel()); 
            // remove the block
            it = blocks.erase(it);
            // move back and keep going
            --it;
        }
    }
}

// create a block if player is level 4
void Game::constructiveForce() {
    // condition for a constructive force
    if (currentLevel == 4 && levelFourCounter >= 5) {
        levelFourCounter = 0;
        // create a new block
        std::unique_ptr<AbstractBlock> special = std::make_unique<SpecialBlock>(&board, 4);
        // see if that cleared any rows
        checkRows();
    }
}


// getter
bool Game::isHeavy(){
    return heavy;
}

// moving blocks
void Game::left() {
    blocks[0]->left();
}

void Game::right() {
    blocks[0]->right();
}

void Game::down() {
    blocks[0]->down();
}

void Game::rotateCW() {
    blocks[0]->rotate(false);
}

void Game::rotateCCW() {
    blocks[0]->rotate(true);
}

void Game::drop() {
    // if there's no block, create a new one and drop it
    //   this functionality is for number-prefixed commands
    if (currBlock == nullptr) {
        genBlock();
    }
    blocks[0]->drop();
    currBlock = nullptr;
    // see if that cleared anything
    checkRows();
}

// set the game to random
void Game::random() {
    // only if level 3 or 4
    if (currentLevel == 3 || currentLevel == 4) {
        level->random();
    } 
}

// stop level from being random
void Game::noRandom(std::string f) {
    if (currentLevel == 3 || currentLevel == 4) {
        level->noRandom(f);
    } 
}

// increment level
void Game::levelUp() {
    if (0 <= currentLevel && currentLevel <= 3) {
        currentLevel++;
        switch (currentLevel) {
            case 1:
                level = std::make_unique<LevelOne>();
                break;
            case 2:
                level = std::make_unique<LevelTwo>();
                break;
            case 3:
                level = std::make_unique<LevelThree>();
                break;
            case 4:
                level = std::make_unique<LevelFour>();
                break;
        }
    }
}

// decrement level
void Game::levelDown(std::string f) {
    if (1 <= currentLevel && currentLevel <= 4) {
        currentLevel--;
        switch (currentLevel) {
            case 0:
                level = std::make_unique<LevelZero>(f);
                break;
            case 1:
                level = std::make_unique<LevelOne>();
                break;
            case 2:
                level = std::make_unique<LevelTwo>();
                break;
            case 3:
                level = std::make_unique<LevelThree>();
                break;
        }
    }
}

// apply the heavy effect for level 3 and 4
// return true if not dropped
// return false if dropped (turn is over)
bool Game::levelHeavy() {
    if (currentLevel >= 3) {
        // move down and check if it moved
        int prev = blocks[0]->getT();
        blocks[0]->down();
        // if it didn't move, block is dropped 
        if (blocks[0]->getT() == prev) {
            blocks[0]->drop();
            return false;
        }
    }
    return true;
}

// applies the heavy special action 
bool Game::specialHeavy() {
    if (heavy) {
        // move down
        int prev = blocks[0]->getT();
        blocks[0]->down();
        blocks[0]->down();
        // if didn't move, block is dropped
        if (blocks[0]->getT() == prev) {
            blocks[0]->drop();
            return false;
        }
    }
    return true;
}

// blind the board
void Game::makeBlind() {
    blind = true;
    for (int y = 2; y <= 11; ++y) {
        for (int x = 2; x <= 8; ++x) {
            board.board[y][x]->setHidden(true);
        }
    }
}

void Game::unblind() {
    blind = false;
    for (int y = 0; y < 18; ++y) {
        for (int x = 0; x < 11; ++x) {
            board.board[y][x]->setHidden(false);
        }
    }
}

void Game::makeHeavy() {
    heavy = true;
}

void Game::replaceI() {
    blocks[0]->removeBlock(0, 0);
    blocks.erase(blocks.begin());
    blocks.insert(blocks.begin(), level->generateBlock(&board, 'I'));
}

void Game::replaceJ() {
    blocks[0]->removeBlock(0, 0);
    blocks.erase(blocks.begin());
    blocks.insert(blocks.begin(), level->generateBlock(&board, 'J'));
}

void Game::replaceL() {
    blocks[0]->removeBlock(0, 0);
    blocks.erase(blocks.begin());
    blocks.insert(blocks.begin(), level->generateBlock(&board, 'L'));
}

void Game::replaceO() {
    blocks[0]->removeBlock(0, 0);
    blocks.erase(blocks.begin());
    blocks.insert(blocks.begin(), level->generateBlock(&board, 'O'));
}

void Game::replaceS() {
    blocks[0]->removeBlock(0, 0);
    blocks.erase(blocks.begin());
    blocks.insert(blocks.begin(), level->generateBlock(&board, 'S'));
}

void Game::replaceT() {
    blocks[0]->removeBlock(0, 0);
    blocks.erase(blocks.begin());
    blocks.insert(blocks.begin(), level->generateBlock(&board, 'T'));
}

void Game::replaceZ() {
    blocks[0]->removeBlock(0, 0);
    blocks.erase(blocks.begin());
    blocks.insert(blocks.begin(), level->generateBlock(&board, 'Z'));
}


