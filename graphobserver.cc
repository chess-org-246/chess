#include "graphobserver.h"


graphobserver::graphobserver(Match *match){
    this->match = match;
    this->w = new Xwindow(width, height);

    w->fillRectangle(0, 0, width+100, height+100, 1);
    w->fillRectangle(0,0,width, 40, 0);
    w->fillRectangle(width/2-(40*gap),0, 40*gap, height, 0);
    // for(int i = 0;i<12;i++){
    //     w->fillRectangle(i*40, 0, 1, height, 0);
    // }
    // for(int i = 0;i<18+1;i++){
    //     w->fillRectangle(0, i*40, 440, 1, 0);
    // }
    w->fillRectangle(0, height-80, width, 80, 0);
    w->drawString(width/2-40, 30, "BIQUADRIS");
    w->drawString(width/4-40, 30, "PLAYER 1");
    w->drawString(3*width/4, 30, "PLAYER 2");
    w->drawString(width/8-40, height-50, "Level: " + std::to_string(match->getLevel(1)));
    w->drawString(5*width/8-40, height-50, "Level: " + std::to_string(match->getLevel(2)));
    
    w->drawString(2*width/8-40, height-50, "Next Block: ");
    w->drawString(6*width/8-40, height-50, "Next Block: ");
    

    w->drawString(width/8-40, height-20, "Score: " + std::to_string(match->getScore(1)));
    w->drawString(5*width/8-40, height-20, "Score: " + std::to_string(match->getScore(2)));

    // w->fillRectangle(40*10, 17*40, 40, 40, 1);
    match->attach(this);
}

void graphobserver::notify(){
    dict['I'] = 5;
    dict['J'] = 4;
    dict['L'] = 8;
    dict['O'] = 6;
    dict['S'] = 3;
    dict['Z'] = 2;
    dict['T'] = 7;
    dict['.'] = 1;
    // int offset = 0;
    char c;
    // std::cout << "playernum" << playerNum << std::endl;

    // if(playerNum == 2){
    //     offset = 12;
    // }

    w->drawString(width/4-40, height-50, "Level: " + std::to_string(match->getLevel(1)));
    w->drawString(3*width/4-40, height-50, "Level: " + std::to_string(match->getLevel(2)));

    w->drawString(width/4-40, height-20, "Score: " + std::to_string(match->getScore(1)));
    w->drawString(3*width/4-40, height-20, "Score: " + std::to_string(match->getScore(2)));
    for (int i = 0; i < height/40; ++i) {
        for (int j = 0; j < width/40; ++j) {
            std::cout << i << " " << j << std::endl;

            if(i < 18 && j < 11){
                // out << "GAME1\n";
                c = match->getState(i,j, 1);
            }
            else if(i < 18 && j >= 11+gap && j < 11+gap+11){
                // out << "GAME2\n";
                c = match->getState(i, j-12, 2);
            }
            else{
                c = '.';
            }
            int val = dict[c];
            // out << "TEST\n";
            // std::cout << "CURRENT:" << match->getState(i,j+offset - gap) << "  PREV:" << match->getPrevState(i,j+offset-gap) << std::endl;
            if((i< 18) && (j < 11) && (match->getState(i, j, 1) != match->getPrevState(i, j,1))){
            // std::cout << "CURRENT:" << match->getState(i,j, 1) << "  PREV:" << match->getPrevState(i,j, 1) << std::endl;
                // std::cout << "YO" << std::endl;
                
                // std::cout << c << " " << j << " " << i << " " << val << std::endl;
                // w->fillRectangle(i*40, 0, 1, height, 0);
                // w->fillRectangle(0, j*40, 440, 1, 0);

                w->fillRectangle(j*40, i*40+40, 40, 40, val);
            }
            else if((i < 18) && (j >= 11+gap) && (j < 11+gap+11) && (match->getState(i, j-12, 2) != match->getPrevState(i, j-12, 2))){
                w->fillRectangle(j*40, i*40+40, 40, 40, val);
            }
        }
    }
    // std::cout << "YOE" << std::endl;
}

graphobserver::~graphobserver(){
    match->detach(this);
    delete this->w;
}
