#include "lblock.h"

LBlock::LBlock(Board * board, int _blockLevel) : AbstractBlock{board, _blockLevel} {
    init_mask();
    blockType = 'L';
    if (testCollisions(t, l, currOrientation)) {
        throw NoSpaceForBlock{};
    }
    updateBoard(0,0);   

}
void LBlock::init_mask() {
    mask.push_back(L1);
    mask.push_back(L2);
    mask.push_back(L3);
    mask.push_back(L4);
}
