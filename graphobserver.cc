#include "graphobserver.h"


graphobserver::graphobserver(Game *game){
    this->game = game;
    this->w = new Xwindow(width, height);

    w->fillRectangle(0, 0, width+100, height+100, 1);
    w->fillRectangle(0,0,width, 40, 0);

    // for(int i = 0;i<12;i++){
    //     w->fillRectangle(i*40, 0, 1, height, 0);
    // }
    // for(int i = 0;i<18+1;i++){
    //     w->fillRectangle(0, i*40, 440, 1, 0);
    // }
    w->drawString(width/2-40, 30, "BIQUADRIS");
    // w->fillRectangle(40*10, 17*40, 40, 40, 1);
    game->attach(this);
}

void graphobserver::notify(){
    std::cout << "YOE" << std::endl;
    char c;
    for (int i = 0; i < height/40; ++i) {
        for (int j = 0; j < width/40; ++j) {
            if(i < 18 && j < 11){
                c = game->getState(i,j);
            }
            else{
                c = '.';
            }
            if((i< 18) && (j< 11) & (game->getState(i, j) != game->getPrevState(i, j))){
            std::cout << "CURRENT:" << game->getState(i,j) << "  PREV:" << game->getPrevState(i,j) << std::endl;
                // std::cout << "YO" << std::endl;
                int val = 1;
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
                std::cout << c << " " << j << " " << i << " " << val << std::endl;
                // w->fillRectangle(i*40, 0, 1, height, 0);
                // w->fillRectangle(0, j*40, 440, 1, 0);

                w->fillRectangle(j*40, i*40+40, 40, 40, val);
            }
        }
    }
    std::cout << "YOE" << std::endl;
}

graphobserver::~graphobserver(){
    game->detach(this);
    delete this->w;
}
