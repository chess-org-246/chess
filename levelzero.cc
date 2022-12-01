#include "levelzero.h"

LevelZero::LevelZero(std::string filename):
    sequence_index{0} {
    ifstream ifs {filename};
    std::string temp;
    while (ifs >> temp) {
        sequence.emplace_back(temp[0]);
    }
}

Block LevelZero::generateBlock(Board* board) {
    // in here, make the right type of block
    switch sequence[sequence_index] {
        case 'I':
            b = std::make_unique<IBlock>(board);
            break;
        case 'J':
            b = std::make_unique<JBlock>(board);
            break;
        case 'L':
            b = std::make_unique<LBlock>(board);
            break;
        case 'O':
             b = std::make_unique<OBlock>(board);
            break;
        case 'S':
            b = std::make_unique<SBlock>(board);
            break;
        case 'T':
            b = std::make_unique<TBlock>(board);
            break;
        case 'Z':
            b = std::make_unique<ZBlock>(board);
            break;
    }
    sequence_index++;
    if (sequence_index >= sequence.size()) {
        sequence_index = 0;
    }

    // return something
}
