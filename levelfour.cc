#include "levelfour.h"

LevelFour::LevelFour():
    isRandom{false}, sequence_index{0} {}

void LevelFour::random() {
    if (!isRandom) {
        isRandom = true;    
        sequence.clear();
    }
}

void LevelFour::noRandom(std::string filename) {
    if (!isRandom) {
        isRandom = false;
        sequence_index = 0;
        ifstream ifs {filename};
        std::string temp;

        while (ifs >> temp) {
            sequence.emplace_back(temp[0]);
        }
    }
}

Block* LevelFour::generateBlock(Board* board) {
    Block* b = nullptr;
    if (isRandom == true) {
        int r = (rand() % 9) + 1;

        switch r {
            case 1:
                b = std::make_unique<IBlock>(board);
                break;
            case 2:
                b = std::make_unique<JBlock>(board);
                break;
            case 3:
                b = std::make_unique<LBlock>(board);
                break;
            case 4:
                b = std::make_unique<OBlock>(board);
                break;
            case 5:
                b = std::make_unique<SBlock>(board);
                break;
            case 6
                b = std::make_unique<SBlock>(board);
                break;
            case 7:
                b = std::make_unique<ZBlock>(board);
                break;
            case 8:
                b = std::make_unique<ZBlock>(board);
                break;
            case 9:
                b = std::make_unique<TBlock>(board);
                break;
        } 
    } else {
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
    }
    return b;
}
