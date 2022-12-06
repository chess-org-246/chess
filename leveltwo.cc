#include "leveltwo.h"

std::unique_ptr<AbstractBlock> LevelTwo::generateBlock(Board* board, char block) {
    std::unique_ptr<AbstractBlock> b;
    try {
        if (block == 'I') {
            b = std::make_unique<IBlock>(board, 2);
        } else if (block == 'J') {
            b = std::make_unique<JBlock>(board, 2);
        } else if (block == 'L') {
            b = std::make_unique<LBlock>(board, 2);
        } else if (block == 'O') {
            b = std::make_unique<OBlock>(board, 2);
        } else if (block == 'S') {
            b = std::make_unique<SBlock>(board, 2);
        } else if (block == 'T') {
            b = std::make_unique<TBlock>(board, 2);
        } else {
            b = std::make_unique<ZBlock>(board, 2);
        }
        return b;
    } catch (NoSpaceForBlock) {
        throw;
    }
}

char LevelTwo::randomizeBlock() {
    int r = (rand() % 7) + 1;
    char b;
    if (r == 1) {
        b = 'I';
    } else if (r == 2) {
        b = 'J';
    } else if (r == 3) {
        b = 'L';
    } else if (r == 4) {
        b = 'O';
    } else if (r == 5) {
        b = 'S';
    } else if (r == 6) {
        b = 'T';
    } else {
        b = 'Z';
    }
    return b;
}

void LevelTwo::random() {
    return;
}

void LevelTwo::noRandom(std::string f) {
    f = f; 
    return;
}
