#include "iblock.h"

IBlock::IBlock(Board * board, int _blockLevel) : AbstractBlock{board, _blockLevel} {
    init_mask();
    blockType = 'I';
    if (testCollisions(t, l, currOrientation)) {
        throw NoSpaceForBlock{};
    }
    updateBoard(0,0);
}
void IBlock::init_mask() {
    mask.push_back(I1);
    mask.push_back(I2);
    mask.push_back(I3);
    mask.push_back(I4);
}