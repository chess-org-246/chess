#include "levelone.h"

std::unique_ptr<AbstractBlock> LevelOne::generateBlock(Board* board) {
    srand(time(NULL));
    int r = (rand() % 12) + 1;
    try {
        if (r == 1) {
            std::unique_ptr<AbstractBlock> b = std::make_unique<IBlock>(board);
            return b;
        } else if (r == 2) {
            std::unique_ptr<AbstractBlock> b = std::make_unique<IBlock>(board);
            return b;
        } else if (r == 3) {
            std::unique_ptr<AbstractBlock> b = std::make_unique<JBlock>(board);
            return b;
        } else if (r == 4) {
            std::unique_ptr<AbstractBlock> b = std::make_unique<JBlock>(board);
            return b;
        } else if (r == 5) {
            std::unique_ptr<AbstractBlock> b = std::make_unique<LBlock>(board);
            return b;
        } else if (r == 6) {
            std::unique_ptr<AbstractBlock> b = std::make_unique<LBlock>(board);
            return b;
        } else if (r == 7) {
            std::unique_ptr<AbstractBlock> b = std::make_unique<OBlock>(board);
            return b;
        } else if (r == 8) {
            std::unique_ptr<AbstractBlock> b = std::make_unique<OBlock>(board);
            return b;
        } else if (r == 9){
            std::unique_ptr<AbstractBlock> b = std::make_unique<SBlock>(board);
            return b;
        } else if(r == 10){
            std::unique_ptr<AbstractBlock> b = std::make_unique<ZBlock>(board);
            return b;
        } else if(r == 11){
            std::unique_ptr<AbstractBlock> b = std::make_unique<TBlock>(board);
            return b;
        } else if(r == 12){
            std::unique_ptr<AbstractBlock> b = std::make_unique<TBlock>(board);
                return b;
        }
    } catch (NoSpaceForBlock) {
        throw;
    }
    throw RandomOutOfRange{};
}
