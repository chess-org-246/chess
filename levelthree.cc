#include "levelthree.h"

LevelThree::LevelThree():
    isRandom{false}, sequence_index{0} {}

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
        ifstream ifs {filename};
        std::string temp;

        while (ifs >> temp) {
            sequence.emplace_back(temp[0]);
        }
    }
}

Block* LevelThree::generateBlock(Game* game) {
    Block* b = nullptr;
    if (isRandom == true) {
        int r = (rand() % 9) + 1;

        switch r {
            case 1:
                b = std::make_unique<IBlock>(game);
                break;
            case 2:
                b = std::make_unique<JBlock>(game);
                break;
            case 3:
                b = std::make_unique<LBlock>(game);
                break;
            case 4:
                b = std::make_unique<OBlock>(game);
                break;
            case 5:
                b = std::make_unique<SBlock>(game);
                break;
            case 6
                b = std::make_unique<SBlock>(game);
                break;
            case 7:
                b = std::make_unique<ZBlock>(game);
                break;
            case 8:
                b = std::make_unique<ZBlock>(game);
                break;
            case 9:
                b = std::make_unique<TBlock>(game);
                break;
        } 
    } else {
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
    }
    return b;
}
