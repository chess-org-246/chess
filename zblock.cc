#include "zblock.h"

ZBlock::ZBlock(Board * board, int _blockLevel) : AbstractBlock{board, _blockLevel} {
    init_mask();
    blockType = 'Z';
    if (testCollisions(t, l, currOrientation)) {
        throw NoSpaceForBlock{};
    }
    updateBoard(0,0);
}

void ZBlock::init_mask() {
    mask.push_back(Z1);
    mask.push_back(Z2);
    mask.push_back(Z3);
    mask.push_back(Z4);
}
