#include "jblock.h"

JBlock::JBlock(Board * board, int _blockLevel) : AbstractBlock{board, _blockLevel} {
    init_mask();
    blockType = 'J';
    if (testCollisions(t, l, currOrientation)) {
        throw NoSpaceForBlock{};
    }
    updateBoard(0,0);
}

void JBlock::init_mask() {
    mask.push_back(J1);
    mask.push_back(J2);
    mask.push_back(J3);
    mask.push_back(J4);
}
