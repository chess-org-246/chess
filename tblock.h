#ifndef TBLOCK_H
#define TBLOCK_H
#include "abstractblock.h"
#include "error.h"


class TBlock : public AbstractBlock {
    void init_mask();
    public:
    TBlock(Board * board, int _blockLevel);
    
};

#endif
