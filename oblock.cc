#include "oblock.h"
#include "error.h"

OBlock::OBlock(Board * board) : AbstractBlock{board} {
    init_mask();
    blockType = 'O';
    if (testCollisions(t, l, currOrientation)) {
        throw NoSpaceForBlock{};
    }
    updateBoard(0,0);   

}
void OBlock::init_mask() {
    std::vector<std::vector<int>> pos1 = {{0,0,0,0},{0,0,0,0},{1,1,0,0},{1,1,0,0}};
    std::vector<std::vector<int>> pos2 = {{0,0,0,0},{0,0,0,0},{1,1,0,0},{1,1,0,0}};
    std::vector<std::vector<int>> pos3 = {{0,0,0,0},{0,0,0,0},{1,1,0,0},{1,1,0,0}};
    std::vector<std::vector<int>> pos4 = {{0,0,0,0},{0,0,0,0},{1,1,0,0},{1,1,0,0}};
    mask.push_back(pos1);
    mask.push_back(pos2);
    mask.push_back(pos3);
    mask.push_back(pos4);
}
