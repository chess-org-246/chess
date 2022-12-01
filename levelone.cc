#include "levelone.h"

Block* LevelOne::generateBlock(Board* board) {
    Block* b = nullptr;
    int r = (rand() % 12) + 1;

    switch r {
        case 1:
            b = std::make_unique<IBlock>(board);
            break;
        case 2:
            b = std::make_unique<IBlock>(board);
            break;
        case 3:
            b = std::make_unique<JBlock>(board);
            break;
        case 4:
            b = std::make_unique<JBlock>(board);
            break;
        case 5:
            b = std::make_unique<LBlock>(board);
            break;
        case 6:
            b = std::make_unique<LBlock>(board);
            break;
        case 7:
            b = std::make_unique<OBlock>(board);
            break;
        case 8:
            b = std::make_unique<OBlock>(board);
            break;
        case 9:
            b = std::make_unique<SBlock>(board);
            break;
        case 10:
            b = std::make_unique<ZBlock>(board);
            break;
        case 11:
            b = std::make_unique<TBlock>(board);
            break;
        case 12:
            b = std::make_unique<TBlock>(board);
            break;
    }
    return b;
}
