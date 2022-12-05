#include "levelone.h"

std::unique_ptr<AbstractBlock> LevelOne::generateBlock(Board* board) {
    std::unique_ptr<AbstractBlock> b;
    int r = (rand() % 12) + 1;
    try {
        if (r == 1) {
            b = std::make_unique<IBlock>(board, 1);
        } else if (r == 2) {
            b = std::make_unique<IBlock>(board, 1);
        } else if (r == 3) {
            b = std::make_unique<JBlock>(board, 1);
        } else if (r == 4) {
            b = std::make_unique<JBlock>(board, 1);
        } else if (r == 5) {
            b = std::make_unique<LBlock>(board, 1);
        } else if (r == 6) {
            b = std::make_unique<LBlock>(board, 1);
        } else if (r == 7) {
            b = std::make_unique<OBlock>(board, 1);
        } else if (r == 8) {
            b = std::make_unique<OBlock>(board, 1);
        } else if (r == 9){
            b = std::make_unique<SBlock>(board, 1);
        } else if(r == 10){
            b = std::make_unique<ZBlock>(board, 1);
        } else if(r == 11){
            b = std::make_unique<TBlock>(board, 1);
        } else {
            b = std::make_unique<TBlock>(board, 1);
        }
        return b;
    } catch (NoSpaceForBlock) {
        throw;
    }
    throw ControlOutOfRange{};
}

void LevelOne::random() {
    return;
}

void LevelOne::noRandom(std::string f) {
    f = f;
    return;
}
