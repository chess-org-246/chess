#ifndef ABSTRACTLEVEL_H
#define ABSTRACTLEVEL_H

#include <string>
class Block; // not sure if include or forward declare

class AbstractLevel {
    Block generateBlock() = 0;
    String file;
};

#endif
