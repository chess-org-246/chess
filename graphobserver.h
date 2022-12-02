#ifndef GRAPHOB_H
#define GRAPHOB_H
#include "window.h"
#include "game.h"
#include "observer.h"
class graphobserver: public Observer{
    Game* game;
    std::ostream &out = std::cout;
    int height = 18,width = 11;
    Xwindow w;

    public:
        ~graphobserver();
        graphobserver(Game *game);
            // studio{studio}, top{top}, bottom{bottom}, left{left}, right{right}{};
        void notify() override;
};

#endif
