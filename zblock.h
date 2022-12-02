#ifndef ZBLOCK_H
#define ZBLOCK_H
#include "abstractblock.h"

class ZBlock : public AbstractBlock {
    void init_mask();
    public:
    ZBlock(Board * board);
    
};

#endif
