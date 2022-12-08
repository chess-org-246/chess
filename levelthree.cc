#include "levelthree.h"

LevelThree::LevelThree():
    isRandom{true}, sequence_index{0} {}

void LevelThree::random() {
    if (!isRandom) {
        isRandom = true;    
        sequence.clear();
    }
}

void LevelThree::noRandom(std::string filename) {
    if (isRandom) {
        isRandom = false;
        std::ifstream ifs {filename};
        sequence_index = 0;
        std::string temp;
        while (ifs >> temp) {
            sequence += temp;
        }
    }
}

std::unique_ptr<AbstractBlock>LevelThree::generateBlock(Board* board, char block) {
    std::unique_ptr<AbstractBlock> b;
    try {
        if (block == 'I') {
            b = std::make_unique<IBlock>(board, 3);
        } else if (block == 'J') {
            b = std::make_unique<JBlock>(board, 3);
        } else if (block == 'L') {
            b = std::make_unique<LBlock>(board, 3);
        } else if (block == 'O') {
            b = std::make_unique<OBlock>(board, 3);
        } else if (block == 'S') {
            b = std::make_unique<SBlock>(board, 3);
        } else if (block == 'T') {
            b = std::make_unique<TBlock>(board, 3);
        } else {
            b = std::make_unique<ZBlock>(board, 3);
        }
        return b;
    } catch (NoSpaceForBlock) {
        throw;
    }
    throw ControlOutOfRange{};
}

char LevelThree::randomizeBlock() {
    char b;
    if (isRandom) {
        int r = (rand() % 9) + 1;
        if (r == 1) {
            b = 'I';
        } else if (r == 2) {
            b = 'J';
        } else if (r == 3) {
            b = 'L';
        } else if (r == 4) {
            b = 'O';
        } else if (r == 5 || r == 6) {
            b = 'S';
        } else if (r == 7) {
            b = 'T';
        } else if (r == 8) {
            b = 'Z';
        } else {
            b = 'Z';
        }
    } else {
        int temp = sequence_index % sequence.length();
        b = sequence[temp];
        sequence_index++;
    }
    return b;
}
