#include "abstractblock.h"

void AbstractBlock::rotate(bool ccw) {
    int prev = currOrientation;
    currOrientation = ccw ? (currOrientation + 1) % 4 : (currOrientation + 3) % 4;
    //std::cout << "surely" << std::endl;
    resetBoard(t,l,prev);
    if (testCollisions(t, l, prev)) {
        currOrientation = prev;
        return;
    }
    //std::cout << "no wau" << std::endl;
    updateBoard(t,l);

}

void AbstractBlock::down() {
    resetBoard(t,l,currOrientation);
    if(!testCollisions(t+1,l,currOrientation)) {   
        updateBoard(t+1,l);
        t++;
        return;
    }
    updateBoard(t,l);
    
}

void AbstractBlock::left() {
    resetBoard(t,l,currOrientation);
    if(!testCollisions(t,l-1,currOrientation)) {   
        updateBoard(t,l-1);
        l--;
        return;
    }
    updateBoard(t,l);
}

void AbstractBlock::drop() {
    int prevt = -999;
    while(prevt != t) {
        prevt = t;
        down();
    }
}


void AbstractBlock::right() {
    resetBoard(t,l,currOrientation);
    if(!testCollisions(t,l+1,currOrientation)) {   
        updateBoard(t,l+1);
        l++;
        return;
    }
    updateBoard(t,l);
}

bool AbstractBlock::testCollisions(int t, int l, int prevmask) {
    bool checkrot = prevmask == currOrientation;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(mask[currOrientation][i][j] && 
              (checkrot || !(mask[prevmask][i][j]))) {
                if (t + i < 18 && l + j < 11 && t + i >= 0 && l + j >= 0
                    && board->board[t+i][l+j]->getChar() == '.') {
                        continue;
                }
                else {
                    return true; 
                }
              }
              
        }
    }
    return false;
}

void AbstractBlock::resetBoard(int t, int l, int orientation) {
    
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if (mask[orientation][i][j]) {
                board->board[t+i][j+l]->setChar('.');
            }
        }
    }      
}

void AbstractBlock::updateBoard(int t, int l) {
  
     for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if (mask[currOrientation][i][j]) {
                board->board[t+i][j+l]->setChar(blockType);
            }
}
}
}

