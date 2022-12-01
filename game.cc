#include "game.h"
#include "cell.h"
#include <vector.h>
char Game::getState(int row, int col){
    return board.board[row][col].charAt();
}

void Game::checkRows(){
    int numOfRowsCleared = 0;
    for(int i = 0;i<height;i++){
        bool fullRow = true;
        for(int j = 0;j <width;j++){
            if(board[i][j] != '.'){
                fullRow = false;
            }
        }
        if(fullRow){
            board.erase(board.begin() + i);
            std::vector<std::unique_ptr<Cell>> vec(width, std::make_unique<Cell>());
            board.emplace(board.begin(), vec);
            numOfRowsCleared++;
        }
    }
    if(numOfRowsCleared == 0){
        levelFourCounter++;
    }
    else if(numOfRowsCleared == 1){
        score += (currentLevel + 1) * (currentLevel + 1);
    }
    else if(numOfRowsCleared >= 2){
        score += (currentLevel + numOfRowsCleared) * (currentLevel + numOfRowsCleared);
        //prompt user for input on which type of speical power they wnat
        speicalAction();
    }
}

void Game::constructiveForce(){

}

void Game::specialAction(){
    std::string input;
    std::cout << "Please "
    std::cin >> input;

}

bool Game::isHeavy(){
    return isHeavy;
}

bool Game::isBlind(){
    return isBlind;
}

