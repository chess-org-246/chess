#ifndef IBLOCK_H
#define IBLOCK_H
#include "abstractblock.h"
#include "error.h"
#include "abstractlevel.h"

class IBlock : public AbstractBlock {
    void init_mask();
    public:
    IBlock(Board * board, int _blockLevel);
    
};

#endif
