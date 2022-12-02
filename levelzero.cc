#include "levelzero.h"

LevelZero::LevelZero(std::string filename):
    sequence_index{0} {
    std::ifstream ifs {filename};
    std::string temp;
    while (ifs >> temp) {
        sequence.emplace_back(temp[0]);
    }
}

AbstractBlock* LevelZero::generateBlock(Board* board) {
    AbstractBlock* b = nullptr;
    // in here, make the right type of block
    try {
        switch (sequence[sequence_index]) {
            case 'I':
                b = std::make_unique<IBlock>(board).get();
                break;
            case 'J':
                b = std::make_unique<JBlock>(board).get();
                break;
            case 'L':
                b = std::make_unique<LBlock>(board).get();
                break;
            case 'O':
                b = std::make_unique<OBlock>(board).get();
                break;
            case 'S':
                b = std::make_unique<SBlock>(board).get();
                break;
            case 'T':
                b = std::make_unique<TBlock>(board).get();
                break;
            case 'Z':
                b = std::make_unique<ZBlock>(board).get();
                break;
        }
        sequence_index++;
        if (sequence_index >= (int) sequence.size()) {
            sequence_index = 0;
        }
    } catch (NoSpaceForBlock) {
        return nullptr;
    }
    return b;
}
