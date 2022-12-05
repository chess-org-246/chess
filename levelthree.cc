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
        sequence_index = 0;
        std::ifstream ifs {filename};
        std::string temp;

        while (ifs >> temp) {
            sequence.emplace_back(temp[0]);
        }
    }
}

std::unique_ptr<AbstractBlock>LevelThree::generateBlock(Board* board) {
    try {
        std::unique_ptr<AbstractBlock> b;
        if (isRandom == true) {
            int r = (rand() % 9) + 1;

            if (r == 1) {
                b = std::make_unique<IBlock>(board, 3);
            } else if (r == 2) {
                b = std::make_unique<JBlock>(board, 3);
            } else if (r == 3) {
                b = std::make_unique<LBlock>(board, 3);
            } else if (r == 4) {
                b = std::make_unique<OBlock>(board, 3);
            } else if (r == 5 || r == 6) {
                b = std::make_unique<SBlock>(board, 3);
            } else if (r == 7) {
                b = std::make_unique<TBlock>(board, 3);
            } else if (r == 8) {
                b = std::make_unique<ZBlock>(board, 3);
            } else {
                b = std::make_unique<ZBlock>(board, 3);
            }
        } else {
            if (sequence[sequence_index] == 'I') {
                b = std::make_unique<IBlock>(board, 3);
            } else if (sequence[sequence_index] == 'J') {
                b = std::make_unique<JBlock>(board, 3);
            } else if (sequence[sequence_index] == 'L') {
                b = std::make_unique<LBlock>(board, 3);
            } else if (sequence[sequence_index] == 'O') {
                b = std::make_unique<OBlock>(board, 3);
            } else if (sequence[sequence_index] == 'S') {
                b = std::make_unique<SBlock>(board, 3);
            } else if (sequence[sequence_index] == 'T') {
                b = std::make_unique<TBlock>(board, 3);
            } else {
                b = std::make_unique<ZBlock>(board, 3);
            }
            sequence_index++;
            if (sequence_index >= (int) sequence.size()) {
                sequence_index = 0;
            }
        }
        return b;
    } catch (NoSpaceForBlock) {
        throw;
    }
    throw ControlOutOfRange{};
}
