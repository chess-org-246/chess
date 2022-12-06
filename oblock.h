#ifndef OBLOCK_H
#define OBLOCK_H
#include "abstractblock.h"
#include "error.h"


class OBlock : public AbstractBlock {
    void init_mask();
    public:
    OBlock(Board * board, int blockLevel);
    
};

#endif
