#include "levelone.h"

Block* LevelOne::generateBlock(Game* game) {
    Block* b = nullptr;
    int r = (rand() % 12) + 1;

    switch r {
        case 1:
            b = unique_ptr(new IBlock(game));
            break;
        case 2:
            b = unique_ptr(new IBlock(game));
            break;
        case 3:
            b = unique_ptr(new JBlock(game));
            break;
        case 4:
            b = unique_ptr(new JBlock(game));
            break;
        case 5:
            b = unique_ptr(new LBlock(game));
            break;
        case 6:
            b = unique_ptr(new LBlock(game));
            break;
        case 7:
            b = unique_ptr(new OBlock(game));
            break;
        case 8:
            b = unique_ptr(new OBlock(game));
            break;
        case 9:
            b = unique_ptr(new SBlock(game));
            break;
        case 10:
            b = unique_ptr(new ZBlock(game));
            break;
        case 11:
            b = unique_ptr(new TBlock(game));
            break;
        case 12:
            b = unique_ptr(new TBlock(game));
            break;
    }
    return b;
}
