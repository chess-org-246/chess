#ifndef LBLOCK_H
#define LBLOCK_H
#include "abstractblock.h"

class LBlock : public AbstractBlock {
    void init_mask();
    public:
    LBlock(Board * board);
    
};

#endif
