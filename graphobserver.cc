#include "graphobserver.h"


graphobserver::graphobserver(Game *game){
    this->game = game;
    // std::cout << "out" << std::endl;
    game->attach(this);
}

void graphobserver::notify(){
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
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
            w.fillRectangle(j*10, i*10, 10, 10, val);
        }
    }
}

graphobserver::~graphobserver(){
    game->detach(this);
}
