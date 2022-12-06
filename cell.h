#ifndef CELL_H
#define CELL_H

// Class for cells on a board
//   Contains information about the state of the board 
class Cell {
    // for blind effect
    bool isHidden = false;

    // current character in a cell
    char curChar;
    unsigned long blockId;

    public:
        // ctor
        Cell(char init);

        // getters and setters
        bool getHidden();
        void setHidden(bool b);
        char getChar();
        void setChar(char c);
        void setBlockId(unsigned long id);
        unsigned long getBlockId();
};

#endif
