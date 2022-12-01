#include "abstractblock.h"

void AbstractBlock::rotate(bool ccw) {
    int tempOrientation = ccw ? (currOrientation + 1) % 4 : (currOrientation + 3) % 4;
    std::vector<std::pair<int,int>> v;
    for(int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (mask[tempOrientation][i][j]) {
                if(board->board[i][j]->getChar() != '.' && !mask[currOrientation][i][j]) {
                    return;
                    //todo throw error
                }
                else {
                    v.emplace_back(i,j);
                }
            }
        }
    }
    for(int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (mask[currOrientation][i][j]) {
                board->board[i][j]->setChar('.');
            }
        }
    }
    for(auto &i : v) {
        board->board[i.first][i.second]->setChar('I');
    }

    currOrientation = tempOrientation;

}