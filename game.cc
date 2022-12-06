#include "game.h"


void Game::printBoard() {
    board.printBoard();
}

Game::Game(int curLevel, std::string filename):
    currentLevel{curLevel} , currBlock{nullptr} {
        filename = filename;
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


char Game::getState(int row, int col){
    return board.board[row][col]->getChar();
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

void Game::setSpecial(bool b) {
    specialActionAvailable = b;
}

void Game::genBlock() {
    char first = level->randomizeBlock();
    if (nextBlock == '!') {
        nextBlock = level->randomizeBlock();
        blocks.insert(blocks.begin(), level->generateBlock(&board, first));
    } else {
        blocks.insert(blocks.begin(), level->generateBlock(&board, nextBlock));
    }
    nextBlock = first;
    currBlock = blocks[0].get();
}

void Game::checkRows() {
    int numOfRowsCleared = 0;
    for(int i = 0;i < height; ++i){
        bool fullRow = true;
        for(int j = 0; j < width;j++){
            if(board.board[i][j]->getChar() == '.'){
                fullRow = false;
            }
        }
        if(fullRow) {
            board.board.erase(board.board.begin() + i);
            std::vector<std::unique_ptr<Cell>> vec;
            for (int k = 0; k < width; ++k) {
                std::unique_ptr<Cell> p {new Cell('.')};
                vec.push_back(std::move(p));
            }
            //std::vector<std::unique_ptr<Cell>> vec(width, std::make_unique<Cell>('.'));
            board.board.insert(board.board.begin(), std::move(vec));
            numOfRowsCleared++;
        }
    }
    if (numOfRowsCleared == 0) {
        levelFourCounter++;
    } else if(numOfRowsCleared == 1){
        score += (currentLevel + 1) * (currentLevel + 1);
        levelFourCounter = 0;
    } else if(numOfRowsCleared >= 2){
        levelFourCounter = 0;
        score += (currentLevel + numOfRowsCleared) * (currentLevel + numOfRowsCleared);
        //prompt user for input on which type of speical power they wnat
        // specialAction();
        specialActionAvailable = true;
    }
    for (auto it = blocks.begin(); it != blocks.end(); ++it) {
        if (!((*it)->checkCells())) {
            score += (1 + (*it)->getBlockLevel()) * (1 + (*it)->getBlockLevel());
            it = blocks.erase(it);
            --it;
        }
    }
}

void Game::constructiveForce() {
    if (currentLevel == 4 && levelFourCounter >= 5) {
        levelFourCounter = 0;
        // TODO spawn obstacle
    }
}


bool Game::isHeavy(){
    return heavy;
}

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
    blocks[0]->rotate(true);
}

void Game::rotateCCW() {
    blocks[0]->rotate(false);
}

void Game::drop() {
    if (currBlock == nullptr) {
        genBlock();
    }
    blocks[0]->drop();
    currBlock = nullptr;
    checkRows();
}

void Game::random() {
    if (currentLevel == 3 || currentLevel == 4) {
        level->random();
    } 
}

void Game::noRandom(std::string f) {
    if (currentLevel == 3 || currentLevel == 4) {
        level->noRandom(f);
    } 
}

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

// return true if not dropped
// returjn false if dropped (turn is over)
bool Game::levelHeavy() {
    if (currentLevel >= 3) {
        int prev = blocks[0]->getT();
        blocks[0]->down();
        if (blocks[0]->getT() == prev) {
            blocks[0]->drop();
            return false;
        }
    }
    return true;
}

bool Game::specialHeavy() {
    if (heavy) {
        int prev = blocks[0]->getT();
        blocks[0]->down();
        blocks[0]->down();
        if (blocks[0]->getT() == prev) {
            blocks[0]->drop();
            return false;
        }
    }
    return true;
}

void Game::makeBlind() {
    for (int y = 2; y <= 11; ++y) {
        for (int x = 2; x <= 8; ++x) {
            board.board[y][x]->setHidden(true);
        }
    }
}

void Game::makeHeavy() {
    heavy = true;
}

void Game::replaceI() {
    blocks[0]->removeBlock(0, 0);
    blocks.erase(blocks.begin());
    blocks.insert(blocks.begin(), std::make_unique<IBlock>(&board, currentLevel));
}

void Game::replaceJ() {
    blocks[0]->removeBlock(0, 0);
    blocks.erase(blocks.begin());
    blocks.insert(blocks.begin(), std::make_unique<JBlock>(&board, currentLevel));
}

void Game::replaceL() {
    blocks[0]->removeBlock(0, 0);
    blocks.erase(blocks.begin());
    blocks.insert(blocks.begin(), std::make_unique<LBlock>(&board, currentLevel));
}

void Game::replaceO() {
    blocks[0]->removeBlock(0, 0);
    blocks.erase(blocks.begin());
    blocks.insert(blocks.begin(), std::make_unique<OBlock>(&board, currentLevel));
}

void Game::replaceS() {
    blocks[0]->removeBlock(0, 0);
    blocks.erase(blocks.begin());
    blocks.insert(blocks.begin(), std::make_unique<SBlock>(&board, currentLevel));
}

void Game::replaceT() {
    blocks[0]->removeBlock(0, 0);
    blocks.erase(blocks.begin());
    blocks.insert(blocks.begin(), std::make_unique<TBlock>(&board, currentLevel));
}

void Game::replaceZ() {
    blocks[0]->removeBlock(0, 0);
    blocks.erase(blocks.begin());
    blocks.insert(blocks.begin(), std::make_unique<ZBlock>(&board, currentLevel));
}


