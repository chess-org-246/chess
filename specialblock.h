#ifndef SPECIALBLOCK_H
#define SPECIALBLOCK_H
#include "abstractblock.h"

class SpecialBlock : public AbstractBlock {
    void init_mask();
    public:
    SpecialBlock(Board * board, int _blockLevel);
    
};

#endif
