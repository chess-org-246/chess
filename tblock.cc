#include "tblock.h"

TBlock::TBlock(Board * board, int _blockLevel) : AbstractBlock{board, _blockLevel} {
    init_mask();
    blockType = 'T';
    if (testCollisions(t, l, currOrientation)) {
        throw NoSpaceForBlock{};
    }
    updateBoard(0,0);   

}
void TBlock::init_mask() {
    mask.push_back(T1);
    mask.push_back(T2);
    mask.push_back(T3);
    mask.push_back(T4);
}
