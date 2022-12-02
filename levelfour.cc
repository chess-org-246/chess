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
        std::ifstream ifs {filename};
        std::string temp;

        while (ifs >> temp) {
            sequence.emplace_back(temp[0]);
        }
    }
}

AbstractBlock* LevelFour::generateBlock(Board* board) {
    AbstractBlock* b = nullptr;
    try {
        if (isRandom == true) {
            int r = (rand() % 9) + 1;

            switch (r) {
                case 1:
                    b = std::make_unique<IBlock>(board).get();
                    break;
                case 2:
                    b = std::make_unique<JBlock>(board).get();
                    break;
                case 3:
                    b = std::make_unique<LBlock>(board).get();
                    break;
                case 4:
                    b = std::make_unique<OBlock>(board).get();
                    break;
                case 5:
                    b = std::make_unique<SBlock>(board).get();
                    break;
                case 6:
                    b = std::make_unique<SBlock>(board).get();
                    break;
                case 7:
                    b = std::make_unique<ZBlock>(board).get();
                    break;
                case 8:
                    b = std::make_unique<ZBlock>(board).get();
                    break;
                case 9:
                    b = std::make_unique<TBlock>(board).get();
                    break;
            } 
        } else {
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
        }
    } catch (NoSpaceForBlock) {
        return nullptr;
    }
    
    return b;
}
