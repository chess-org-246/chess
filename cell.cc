#include "cell.h"

Cell::Cell(char init = '.') : curChar{init} {}

bool Cell::getHidden() {
    return isHidden;
}

void Cell::setHidden(bool b) {
    isHidden = b;
}

char Cell::getChar() {
    return curChar;
}

void Cell::setChar(char c) {
    curChar = c;
}

void Cell::setBlockId(unsigned long i) { 
    blockId = i;
}

unsigned long Cell::getBlockId() {
    return blockId;
}

