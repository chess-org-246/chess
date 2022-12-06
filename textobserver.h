#ifndef TEXTOB_H
#define TEXTOB_H
#include <iomanip>  
#include <vector>
#include "observer.h"
// #include "window.h"
#include "game.h"
#include "match.h"


class textobserver: public Observer{
    Match* match;
    std::ostream &out = std::cout;
    // int top, bottom, left, right;

    public:
        ~textobserver();
        textobserver(Match * match); 
            // studio{studio}, top{top}, bottom{bottom}, left{left}, right{right}{};
        void notify() override;
};

#endif
