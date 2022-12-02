#include "game.h"


void Game::printBoard() {
    board.printBoard();
}

Game::Game(int curLevel, std::string filename):
    currentLevel{curLevel} {
    filename = filename;
        /*if (curLevel == 0) {
            al = std::make_unique<LevelZero>(filename).get();
            break;*/
        if (curLevel == 1) {
            level = std::make_unique<LevelOne>();
        }
       /*} else if (curLevel == 2){
            level = std::make_unique<LevelTwo>();
        }
        else if (curLevel == 3){
            level = std::make_unique<LevelThree>();
        }
        else if (curLevel == 4){
            level = std::make_unique<LevelFour>();
        }*/
        /*case 2:
            al = std::make_unique<LevelTwo>().get();
            break;
        case 3:
            al = std::make_unique<LevelThree>().get();
            break; 
        case 4:
            al = std::make_unique<LevelFour>().get();
            break;*/
}


char Game::getState(int row, int col){
    return board.board[row][col]->getChar();
}

void Game::genBlock() {
    blocks.insert(blocks.begin(), level->generateBlock(&board));
    
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
    }
    else if(numOfRowsCleared == 1){
        score += (currentLevel + 1) * (currentLevel + 1);
    }
    else if(numOfRowsCleared >= 2){
        score += (currentLevel + numOfRowsCleared) * (currentLevel + numOfRowsCleared);
        //prompt user for input on which type of speical power they wnat
        specialAction();
    }
    for (auto it = blocks.begin(); it != blocks.end(); ++it) {
        if (!((*it)->checkCells())) {
            score += (1 + (*it)->getBlockLevel()) * (1 + (*it)->getBlockLevel());
            it = blocks.erase(it);
            --it;
        }
    }
}

void Game::constructiveForce(){

}

void Game::specialAction(){
    

    
}

bool Game::isHeavy(){
    return heavy;
}

bool Game::isBlind(){
    return blind;
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

void Game::rotate(bool ccw) {
    blocks[0]->rotate(ccw);
}

void Game::drop() {
    blocks[0]->drop();
    checkRows();
}
