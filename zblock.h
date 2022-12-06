#ifndef ZBLOCK_H
#define ZBLOCK_H
#include "abstractblock.h"
#include "error.h"

// initalize the Z block type
class ZBlock : public AbstractBlock { //inhereits from abstract block
    void init_mask(); //create the block mask
    public:
    ZBlock(Board * board, int _blockLevel);
    
};

#endif
