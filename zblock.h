#ifndef ZBLOCK_H
#define ZBLOCK_H
#include "abstractblock.h"
#include "error.h"

class ZBlock : public AbstractBlock {
    void init_mask();
    public:
    ZBlock(Board * board, int _blockLevel);
    
};

#endif
