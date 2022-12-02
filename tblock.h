#ifndef TBLOCK_H
#define TBLOCK_H
#include "abstractblock.h"

class TBlock : public AbstractBlock {
    void init_mask();
    public:
    TBlock(Board * board);
    
};

#endif
