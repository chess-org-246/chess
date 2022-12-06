#include "game.h"


// void Game::printBoard() {
//     this->notifyObservers();
// }

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
// void Game::copyBoard(){
//     for(int i = 0;i<height;i++){
//         for(int j = 0;j<width;j++){
//             prevBoard[i][j] = board.board[i][j]->getChar();
//         }
//     }
// }
// char Game::getPrevState(int row, int col) const{
//     // std::cout << "YOOO" << std::endl;
//     return prevBoard[row][col];
// }

char Game::nextBlock(){
    return nextBlockChar;
}
char Game::getState(int row, int col) const{
    return board.board[row][col]->getChar();
}

int Game::getScore() {
    return score;
}

int Game::getLevel() {
    return currentLevel;
}

// std::vector<std::vector<char>> Game::getNext(){
//     std::vector<std::vector <char>> temp;
//     for(int i = 0;i<4;i++){
//         std::vector<char> temp1;
//         for(int j = 0;j<4;j++){
//             temp1.emplace_back(this->getState(i,j));
//         }
//         temp.emplace_back(temp1);
//     }
//     return temp;
// }

bool Game::getSpecial() {
    return specialActionAvailable;
}

void Game::setSpecial(bool b) {
    specialActionAvailable = b;
}

void Game::genBlock() {
    // copyBoard();
    char first = level->randomizeBlock();
    if (nextBlockChar == '!') {
        nextBlockChar = level->randomizeBlock();
        blocks.insert(blocks.begin(), level->generateBlock(&board, first));
    } else {
        blocks.insert(blocks.begin(), level->generateBlock(&board, nextBlockChar));
    }
    nextBlockChar = first;
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
        std::unique_ptr<AbstractBlock> special = std::make_unique<SpecialBlock>(&board, 4);
        checkRows();
    }
}


bool Game::isHeavy(){
    return heavy;
}

void Game::left() {
    // copyBoard();
    blocks[0]->left();
}

void Game::right() {
    // copyBoard();
        blocks[0]->right();
}

void Game::down() {
    // copyBoard();
    blocks[0]->down();
}


void Game::rotateCW() {
    // copyBoard();
    blocks[0]->rotate(true);
}

void Game::rotateCCW() {
    // copyBoard();
    blocks[0]->rotate(false);
}

void Game::drop() {
    //copyBoard();
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


