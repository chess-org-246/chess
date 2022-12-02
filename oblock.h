#ifndef OBLOCK_H
#define OBLOCK_H
#include "abstractblock.h"

class OBlock : public AbstractBlock {
    void init_mask();
    public:
    OBlock(Board * board);
    
};

#endif
