#include "cell.h"

Cell::Cell(char init = '.') : curChar{init} {}

bool Cell::getHidden() {
    return isHidden;
}

void Cell::setHidden(bool b) {
    isHidden = b;
}

char Cell::getChar() {
    if (isHidden) {
        isHidden = false;
        return '?';
    }
    return curChar;
}

void Cell::setChar(char c) {
    curChar = c;
}