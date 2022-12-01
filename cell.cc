#include "cell.h"

Cell::Cell(char init) : curChar{init} {}

bool Cell::getHidden() {
    return isHidden;
}

char Cell::getChar() {
    return curChar;
}

void Cell::setChar(char c) {
    curChar = c;
}