#ifndef ERROR_H
#define ERROR_H
#include <string>

// Errors to be thrown by methods.
class Error {
    public:
        virtual ~Error() = 0;
};

class NoSpaceForBlock {
    bool isPlayer1 = false;

    public:
        bool getPlayer1();
        void setPlayer1(bool b);
};

class RandomOutOfRange {};

class ControlOutOfRange {};

#endif
