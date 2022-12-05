#include "levelzero.h"

LevelZero::LevelZero(std::string filename):
    sequence_index{0} {
    std::ifstream ifs {filename};
    std::string temp;
    while (ifs >> temp) {
        sequence.emplace_back(temp[0]);
    }
}

std::unique_ptr<AbstractBlock> LevelZero::generateBlock(Board* board) {
    std::unique_ptr<AbstractBlock> b;
    try {
        if (sequence[sequence_index] == 'I') {
            b = std::make_unique<IBlock>(board, 1);
        } else if (sequence[sequence_index] == 'J') {
            b = std::make_unique<JBlock>(board, 1);
        } else if (sequence[sequence_index] == 'L') {
            b = std::make_unique<LBlock>(board, 1);
        } else if (sequence[sequence_index] == 'O') {
            b = std::make_unique<OBlock>(board, 1);
        } else if (sequence[sequence_index] == 'S') {
            b = std::make_unique<SBlock>(board, 1);
        } else if (sequence[sequence_index] == 'T') {
            b = std::make_unique<TBlock>(board, 1);
        } else {
            b = std::make_unique<ZBlock>(board, 1);
        }
        sequence_index++;
        if (sequence_index >= (int) sequence.size()) {
            sequence_index = 0;
        }
        return b;
    } catch (NoSpaceForBlock) {
        throw;
    }
    throw ControlOutOfRange {};
}

void LevelZero::random() {
    return;
}

void LevelZero::noRandom(std::string f) {
    f = f;
    return;
}
