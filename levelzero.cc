#include "levelzero.h"

LevelZero::LevelZero(std::string filename):
    sequence_index{0} {
    ifstream ifs {filename};
    std::string temp;
    while (ifs >> temp) {
        sequence.emplace_back(temp[0]);
    }
}

Block LevelZero::generateBlock() {
    // in here, make the right type of block
    switch sequence[sequence_index] {
        case 'I':
            b = std::make_unique<IBlock>(game);
            break;
        case 'J':
            b = std::make_unique<JBlock>(game);
            break;
        case 'L':
            b = std::make_unique<LBlock>(game);
            break;
        case 'O':
             b = std::make_unique<OBlock>(game);
            break;
        case 'S':
            b = std::make_unique<SBlock>(game);
            break;
        case 'T':
            b = std::make_unique<TBlock>(game);
            break;
        case 'Z':
            b = std::make_unique<ZBlock>(game);
            break;
    }
    sequence_index++;
    if (sequence_index >= sequence.size()) {
        sequence_index = 0;
    }

    // return something
}
