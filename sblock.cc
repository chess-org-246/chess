#include "sblock.h"

SBlock::SBlock(Board * board, int _blockLevel) : AbstractBlock{board, _blockLevel} {
    init_mask();
    blockType = 'S';
    if (testCollisions(t, l, currOrientation)) {
        throw NoSpaceForBlock{};
    }
    updateBoard(0,0);   

}
void SBlock::init_mask() {
    mask.push_back(S1);
    mask.push_back(S2);
    mask.push_back(S3);
    mask.push_back(S4);
}
