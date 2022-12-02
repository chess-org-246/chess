#include "leveltwo.h"

AbstractBlock* LevelTwo::generateBlock(Board* board) {
    AbstractBlock* b = nullptr;
    int r = (rand() % 7) + 1;
    try {
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
                b = std::make_unique<ZBlock>(board).get();
                break;
            case 7:
                b = std::make_unique<TBlock>(board).get();
                break;
        }
    } catch (NoSpaceForBlock) {
        return nullptr;
    }
    return b;
}
