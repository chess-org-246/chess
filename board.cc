#include "board.h"

Board::Board() {
    for(int i = 0; i < 18; i++) {
        // push back rows of vectors
        board.push_back(std::vector<std::unique_ptr<Cell>>());
        for (int j = 0; j < 11; j++) {
            // push back the cells
            board[i].push_back(std::make_unique<Cell>('.'));
        }
    }
}

