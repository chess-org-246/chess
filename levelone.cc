#include "levelone.h"

Block* LevelOne::generateBlock(Game* game) {
    Block* b = nullptr;
    int r = (rand() % 12) + 1;

    switch r {
        case 1:
            b = std::make_unique<IBlock>(game);
            break;
        case 2:
            b = std::make_unique<IBlock>(game);
            break;
        case 3:
            b = std::make_unique<JBlock>(game);
            break;
        case 4:
            b = std::make_unique<JBlock>(game);
            break;
        case 5:
            b = std::make_unique<LBlock>(game);
            break;
        case 6:
            b = std::make_unique<LBlock>(game);
            break;
        case 7:
            b = std::make_unique<OBlock>(game);
            break;
        case 8:
            b = std::make_unique<OBlock>(game);
            break;
        case 9:
            b = std::make_unique<SBlock>(game);
            break;
        case 10:
            b = std::make_unique<ZBlock>(game);
            break;
        case 11:
            b = std::make_unique<TBlock>(game);
            break;
        case 12:
            b = std::make_unique<TBlock>(game);
            break;
    }
    return b;
}
