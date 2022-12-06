#include "levelone.h"

std::unique_ptr<AbstractBlock> LevelOne::generateBlock(Board* board, char block) {
    std::unique_ptr<AbstractBlock> b;
    try {
        if (block == 'I') {
            b = std::make_unique<IBlock>(board, 1);
        } else if (block == 'J') {
            b = std::make_unique<JBlock>(board, 1);
        } else if (block == 'L') {
            b = std::make_unique<LBlock>(board, 1);
        } else if (block == 'O') {
            b = std::make_unique<OBlock>(board, 1);
        } else if (block == 'S') {
            b = std::make_unique<SBlock>(board, 1);
        } else if (block == 'T') {
            b = std::make_unique<TBlock>(board, 1);
        } else {
            b = std::make_unique<ZBlock>(board, 1);
        }
        return b;
    } catch (NoSpaceForBlock) {
        throw;
    }
    throw ControlOutOfRange{};
}

char LevelOne::randomizeBlock() {
    int r = (rand() % 12) + 1;
    char b;
    if (r == 1) {
        b = 'I';
    } else if (r == 2) {
        b = 'I';
    } else if (r == 3) {
        b = 'J';
    } else if (r == 4) {
        b = 'J';
    } else if (r == 5) {
        b = 'L';
    } else if (r == 6) {
        b = 'L';
    } else if (r == 7) {
        b = 'O';
    } else if (r == 8) {
        b = 'O';
    } else if (r == 9){
        b = 'S';
    } else if(r == 10){
        b = 'Z';
    } else if(r == 11){
        b = 'T';
    } else {
        b = 'T';
    }
    return b;
}

void LevelOne::random() {
    return;
}

void LevelOne::noRandom(std::string f) {
    f = f;
    return;
}
