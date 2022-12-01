#include "iblock.h"

IBlock::IBlock(Board * board) : AbstractBlock{board} {
    init_mask();
    for(int i = 0; i < 4; i++) {
        blockCells.push_back(std::vector<Cell*>());
        for (int j = 0; j < 4; j++) {
            if (i == 3) {
                if(board->board[i][j]->getChar() != '.') {
                // TODO: throw error
                }
                board->board[i][j]->setChar('I');
                blockCells[i].push_back(board->board[i][j].get());
            }
            else {
                blockCells[i].push_back(board->board[i][j].get());
            }
        }
    }
}
void IBlock::init_mask() {
    std::vector<std::vector<int>> pos1 = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{1,1,1,1}};
    std::vector<std::vector<int>> pos2 = {{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0}};
    std::vector<std::vector<int>> pos3 = {{1,1,1,1},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    std::vector<std::vector<int>> pos4 = {{0,0,0,1},{0,0,0,1},{0,0,0,1},{0,0,0,1}};
    mask.push_back(pos1);
    mask.push_back(pos2);
    mask.push_back(pos3);
    mask.push_back(pos4);
}