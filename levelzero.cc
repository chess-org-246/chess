#include "levelzero.h"

LevelZero::LevelZero(std::string filename):
    sequence_index{0} {
    std::ifstream ifs {filename};
    std::string temp;
    while (ifs >> temp) {
        sequence.emplace_back(temp[0]);
    }
}

//generate the block based on the letter passed
std::unique_ptr<AbstractBlock> LevelZero::generateBlock(Board* board, char block) {
    std::unique_ptr<AbstractBlock> b;
    try {
        if (block == 'I') {
            b = std::make_unique<IBlock>(board, 0); //each block pointer has a board and level
        } else if (block == 'J') {
            b = std::make_unique<JBlock>(board, 0);
        } else if (block == 'L') {
            b = std::make_unique<LBlock>(board, 0);
        } else if (block == 'O') {
            b = std::make_unique<OBlock>(board, 0);
        } else if (block == 'S') {
            b = std::make_unique<SBlock>(board, 0);
        } else if (block == 'T') {
            b = std::make_unique<TBlock>(board, 0);
        } else {
            b = std::make_unique<ZBlock>(board, 0);
        }
        return b;
    } catch (NoSpaceForBlock) {
        throw;
    }
    throw ControlOutOfRange {};
}

char LevelZero::randomizeBlock() { //selects a char from the sequence
    char b = sequence[sequence_index];
    sequence_index++;
    if (sequence_index >= (int) sequence.size()) {
        sequence_index = 0;
    }
    return b;
}

void LevelZero::random() { //empty declaration
    return;
}

void LevelZero::noRandom(std::string f) {//empty declaration
    f = f;
    return;
}
