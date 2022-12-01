#ifndef IBLOCK_H
#define IBLOCK_H
#include "abstractblock.h"

class IBlock : public AbstractBlock {
    void init_mask();
    public:
    IBlock(Board * board);
    
};

#endif
