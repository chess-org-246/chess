#ifndef SBLOCK_H
#define SBLOCK_H
#include "abstractblock.h"
#include "error.h"


class SBlock : public AbstractBlock {
    void init_mask();
    public:
    SBlock(Board * board, int _blockLevel);
    
};

#endif
