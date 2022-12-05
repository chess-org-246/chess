#ifndef CELL_H
#define CELL_H
class Cell {
    bool isHidden = false;
    char curChar;

    public:
        Cell(char init);
        bool getHidden();
        void setHidden(bool b);
        char getChar();
        void setChar(char c);
};

#endif
