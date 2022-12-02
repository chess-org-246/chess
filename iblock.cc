#include "iblock.h"
#include "error.h"
#include "abstractlevel.h"

IBlock::IBlock(Board * board) : AbstractBlock{board} {
    init_mask();
    blockType = 'I';
    if (testCollisions(t, l, currOrientation)) {
        throw NoSpaceForBlock{};
    }
    updateBoard(0,0);
}
void IBlock::init_mask() {
    std::vector<std::vector<int>> pos1 = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{1,1,1,1}};
    std::vector<std::vector<int>> pos2 = {{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0}};
    std::vector<std::vector<int>> pos3 = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{1,1,1,1}};
    std::vector<std::vector<int>> pos4 = {{1,0,0,0},{1,0,0,0},{1,0,0,0},{1,0,0,0}};
    mask.push_back(pos1);
    mask.push_back(pos2);
    mask.push_back(pos3);
    mask.push_back(pos4);
}