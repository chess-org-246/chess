#ifndef CELL_H
#define CELL_H
class Cell {
    bool isHidden;
    char curChar;

    public:
        Cell(char init);
        bool getHidden();
        char getChar();
        void setChar(char c);
};

#endif
