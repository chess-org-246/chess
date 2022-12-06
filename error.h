#ifndef ERROR_H
#define ERROR_H


// Errors to be thrown by methods.
class Error {
    public:
        virtual ~Error() = 0;
};

class NoSpaceForBlock {};

class RandomOutOfRange {};

class ControlOutOfRange {};

#endif
