#include "leveltwo.h"

std::unique_ptr<AbstractBlock> LevelTwo::generateBlock(Board* board) {
    std::unique_ptr<AbstractBlock> b;

    int r = (rand() % 7) + 1;
    try {
        if (r == 1) {
            b = std::make_unique<IBlock>(board, 2);
        } else if (r == 2) {
            b = std::make_unique<JBlock>(board, 2);
        } else if (r == 3) {
            b = std::make_unique<LBlock>(board, 2);
        } else if (r == 4) {
            b = std::make_unique<OBlock>(board, 2);
        } else if (r == 5) {
            b = std::make_unique<SBlock>(board, 2);
        } else if (r == 6) {
            b = std::make_unique<TBlock>(board, 2);
        } else {
            b = std::make_unique<ZBlock>(board, 2);
        }
        return b;
    } catch (NoSpaceForBlock) {
        throw;
    }
}

void LevelTwo::random() {
    return;
}

void LevelTwo::noRandom(std::string f) {
    f = f; 
    return;
}
