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
            break;
        case 'J':
            break;
        case 'L':
            break;
        case 'O':
            break;
        case 'S':
            break;
        case 'T':
            break;
        case 'Z':
            break;
    }
    sequence_index++;
    if (sequence_index >= sequence.size()) {
        sequence_index = 0;
    }

    // return something
}
