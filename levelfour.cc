#include "levelfour.h"

LevelFour::LevelFour():
    isRandom{true}, sequence_index{0} {}

void LevelFour::random() {
    if (!isRandom) {
        isRandom = true;    
        sequence.clear();
    }
}

void LevelFour::noRandom(std::string filename) {
    if (isRandom) {
        isRandom = false;
        sequence_index = 0;
        std::ifstream ifs {filename};
        std::string temp;

        while (ifs >> temp) {
            sequence.emplace_back(temp[0]);
        }
    }
}

std::unique_ptr<AbstractBlock> LevelFour::generateBlock(Board* board, char block) {
   std::unique_ptr<AbstractBlock> b;
    try {
        if (block == 'I') {
            b = std::make_unique<IBlock>(board, 4);
        } else if (block == 'J') {
            b = std::make_unique<JBlock>(board, 4);
        } else if (block == 'L') {
            b = std::make_unique<LBlock>(board, 4);
        } else if (block == 'O') {
            b = std::make_unique<OBlock>(board, 4);
        } else if (block == 'S') {
            b = std::make_unique<SBlock>(board, 4);
        } else if (block == 'T') {
            b = std::make_unique<TBlock>(board, 4);
        } else {
            b = std::make_unique<ZBlock>(board, 4);
        }
        return b;
    } catch (NoSpaceForBlock) {
        throw;
    }
    throw ControlOutOfRange{};
}

char LevelFour::randomizeBlock() {
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
        b = sequence[sequence_index];
        sequence_index++;
        if (sequence_index >= (int) sequence.size()) {
            sequence_index = 0;
        }
    }
    return b;
}
