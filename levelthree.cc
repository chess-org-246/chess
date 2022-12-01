#include "levelthree.h"

LevelThree::LevelThree():
    isRandom{false}, sequence_index{0} {}

void LevelThree::random() {
    isRandom = true;
}

void LevelThree::noRandom(std::string filename) {
    isRandom = false;
    sequence_index = 0;
    ifstream ifs {filename};
    std::string temp;

    while (ifs >> temp) {
        sequence.emplace_back(temp[0]);
    }
}

Block LevelThree::generateBlock(Game* game) {
    if (isRandom == true) {
        int r = (rand() % 9) + 1;

        switch r {
            case 1:
                b = unique_ptr(new IBlock(game));
                break;
            case 2:
                b = unique_ptr(new JBlock(game));
                break;
            case 3:
                b = unique_ptr(new LBlock(game));
                break;
            case 4:
                b = unique_ptr(new OBlock(game));
                break;
            case 5:
                b = unique_ptr(new SBlock(game));
                break;
            case 6
                b = unique_ptr(new SBlock(game));
                break;
            case 7:
                b = unique_ptr(new ZBlock(game));
                break;
            case 8:
                b = unique_ptr(new ZBlock(game));
                break;
            case 9:
                b = unique_ptr(new TBlock(game));
                break;
        } 
    } else {
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
    }
}
