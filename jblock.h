#ifndef JBLOCK_H
#define JBLOCK_H
#include "abstractblock.h"

class JBlock : public AbstractBlock {
    void init_mask();
    public:
        JBlock(Board * board, int _blockLevel);
    
};

#endif
