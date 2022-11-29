#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include "cell.h"

class Board {
    std::vector<std::vector<unique_ptr<Cell>>> board; /* 18 rows * 11 cols */
};

#endif
