#ifndef TEXTOB_H
#define TEXTOB_H
#include "observer.h"
// #include "window.h"
#include "game.h"


class textobserver: public Observer{
    Game* game;
    std::ostream &out = std::cout;
    // int top, bottom, left, right;

    public:
        ~textobserver();
        textobserver(Game* game); 
            // studio{studio}, top{top}, bottom{bottom}, left{left}, right{right}{};
        void notify() override;
};

#endif
