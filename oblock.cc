#include "oblock.h"

OBlock::OBlock(Board * board, int _blockLevel) : AbstractBlock{board, _blockLevel} {
    init_mask();
    blockType = 'O';
    if (testCollisions(t, l, currOrientation)) {
        throw NoSpaceForBlock{};
    }
    updateBoard(0,0);   

}
void OBlock::init_mask() {
    mask.push_back(O1);
    mask.push_back(O2);
    mask.push_back(O3);
    mask.push_back(O4);
}
