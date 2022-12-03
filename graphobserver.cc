#include "graphobserver.h"


graphobserver::graphobserver(Game *game){
    this->game = game;
    this->w = new Xwindow(width, height);
    game->attach(this);
}

void graphobserver::notify(){
    for (int i = 0; i < height/40; ++i) {
        for (int j = 0; j < width/40; ++j) {
            // std::cout << "YOE" << std::endl;
            char c = game->getState(i,j);
            int val = 0;
            if (c == 'I'){
                val = 5;
            }
            else if (c == 'J'){
                val = 4;
            }
            else if (c == 'L'){
                val = 8;
            }
            else if (c == 'O'){
                val = 6;
            }
            else if (c == 'S'){
                val = 3;
            }
            else if (c == 'Z'){
                val = 2;
            }
            else if (c == 'T'){
                val = 7;
            }
            // std::cout << c << " " << val << std::endl;
            w->fillRectangle(j*40, i*40, 40, 40, val);
        }
    }
}

graphobserver::~graphobserver(){
    game->detach(this);
    delete this->w;
}
