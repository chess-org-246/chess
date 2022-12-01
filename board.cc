#include "board.h"

Board::Board() {
    for(int i = 0; i < 18; i++) {
        board.push_back(std::vector<std::unique_ptr<Cell>>());
        for (int j = 0; j < 11; j++) {
            board[i].push_back(std::make_unique<Cell>('.'));
        }
    }
}

void Board::printBoard() {
    std::cout << "-------------------------" << std::endl;
    for(int i = 0; i < 18; i++) {
        std::cout << "| ";
        for (int j = 0; j < 11; j++) {
            std::cout << board[i][j]->getChar() << " ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << "-------------------------" << std::endl;
}

