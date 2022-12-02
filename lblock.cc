#include "lblock.h"
#include "error.h"

LBlock::LBlock(Board * board, int _blockLevel) : AbstractBlock{board, _blockLevel} {
    init_mask();
    blockType = 'L';
    if (testCollisions(t, l, currOrientation)) {
        throw NoSpaceForBlock{};
    }
    updateBoard(0,0);   

}
void LBlock::init_mask() {
    std::vector<std::vector<int>> pos1 = {{0,0,0,0},{0,0,0,0},{0,0,1,0},{1,1,1,0}};
    std::vector<std::vector<int>> pos2 = {{0,0,0,0},{1,0,0,0},{1,0,0,0},{1,1,0,0}};
    std::vector<std::vector<int>> pos3 = {{0,0,0,0},{0,0,0,0},{1,1,1,0},{1,0,0,0}};
    std::vector<std::vector<int>> pos4 = {{0,0,0,0},{1,1,0,0},{0,1,0,0},{0,1,0,0}};
    mask.push_back(pos1);
    mask.push_back(pos2);
    mask.push_back(pos3);
    mask.push_back(pos4);
}
