#ifndef LBLOCK_H
#define LBLOCK_H
#include "abstractblock.h"
#include "error.h"


class LBlock : public AbstractBlock {
    void init_mask();
    public:
    LBlock(Board * board, int _blockLevel);
    
};

#endif
