#include "levelone.h"

LevelOne::LevelOne(int _seed): 
    seed{_seed} {}

Block LevelOne::generateBlock() {
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> distrib(1, 12); 
    int r = distrib(gen);

    switch r {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
    }
}