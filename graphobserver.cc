#include "graphobserver.h"


graphobserver::graphobserver(Match *match){
    this->match = match;
    this->w = new Xwindow(width, height);

    w->fillRectangle(0, 0, width+100, height+100, 1);
    w->fillRectangle(0,0,width, 40, 0);
    w->fillRectangle(width/2-(40*gap),0, 40*gap, height, 0);

    w->fillRectangle(0, height-80, width, 80, 0);
    w->drawString(width/2-40, 30, "BIQUADRIS");
    w->drawString(width/4-40, 30, "PLAYER 1");
    w->drawString(3*width/4, 30, "PLAYER 2");
    w->drawString(width/8-40, height-50, "Level: " + std::to_string(match->getLevel(1)));
    w->drawString(5*width/8-40, height-50, "Level: " + std::to_string(match->getLevel(2)));
    
    w->drawString(2*width/8-40, height-50, "Next Block: ");
    w->fillRectangle(2*width/8-40+70, height-50-20, 60, 60, 1);

    w->drawString(6*width/8-40, height-50, "Next Block: ");
    w->fillRectangle(6*width/8-40+70, height-50-20, 60, 60, 1);
    

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
    

    std::vector<std::vector<int>> temp1;
    int nextBlockColourP1 = 0;
    switch(match->nextBlock(1)){
        case 'I':
            temp1 = I1;
            break;
        case 'J':
            temp1 = J1;
            break;
        case 'L':
            temp1 = L1;
            break;
        case 'O':
            temp1 = O1;
            break;
        case 'S':
            temp1 = S1;
            break;
        case 'Z':
            temp1 = Z1;
            break;
        case 'T':
            temp1 = T1;
            break;

    }
    nextBlockColourP1 = dict[match->nextBlock(1)];
    std::vector<std::vector<int>> temp2;
    int nextBlockColourP2 = 0;
    switch(match->nextBlock(2)){
        case 'I':
            temp2 = I1;
            break;
        case 'J':
            temp2 = J1;
            break;
        case 'L':
            temp2 = L1;
            break;
        case 'O':
            temp2 = O1;
            break;
        case 'S':
            temp2 = S1;
            break;
        case 'Z':
            temp2 = Z1;
            break;
        case 'T':
            temp2 = T1;
            break;

    }
    nextBlockColourP2 = dict[match->nextBlock(2)];
    out << nextBlockColourP1 << nextBlockColourP2 << std::endl;
    char c;
    // std::cout << "playernum" << playerNum << std::endl;
    out << "HI\n";
    // if(playerNum == 2){
    //     offset = 12;
    // }

    w->drawString(width/8-40, height-50, "Level: " + std::to_string(match->getLevel(1)));
    w->drawString(5*width/8-40, height-50, "Level: " + std::to_string(match->getLevel(2)));
    w->drawString(width/8-40, height-20, "Score: " + std::to_string(match->getScore(1)));
    w->drawString(5*width/8-40, height-20, "Score: " + std::to_string(match->getScore(2)));
    
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            w->fillRectangle((2*width/8-40+70)+i*15, (height-50-20)+j*15, 15, 15, 1);
            w->fillRectangle((6*width/8-40+70)+i*15, (height-50-20)+j*15, 15, 15, 1);
        }
    }
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            if(temp1[j][i]){
                // out << "E\n";
                w->fillRectangle((2*width/8-40+70)+i*15, (height-50-20)+j*15, 15, 15, nextBlockColourP1);
            }
            if(temp2[j][i]){
                // out << "F\n";;
                w->fillRectangle((6*width/8-40+70)+i*15, (height-50-20)+j*15, 15, 15, nextBlockColourP2);
            }
        }
    }

    for (int i = 0; i < height/40; ++i) {
        for (int j = 0; j < width/40; ++j) {
            // std::cout << i << " " << j << std::endl;

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
            
            if((i< 18) && (j < 11) && (match->getState(i, j, 1) != prevBoard1[i][j])){
                
                w->fillRectangle(j*40, i*40+40, 40, 40, val);
            }
            else if((i < 18) && (j >= 11+gap) && (j < 11+gap+11) && (match->getState(i, j-12, 2) != prevBoard2[i][j])){
                w->fillRectangle(j*40, i*40+40, 40, 40, val);
            }
        }
    }
    out << "TEST\n";
    for(int i = 0;i<18;i++){
        for(int j = 0;j<11;j++){
            prevBoard1[i][j] = match->getState(i, j, 1);
        }
    }
    for(int i = 0;i<18;i++){
        for(int j = 0;j<11;j++){
            prevBoard2[i][j] = match->getState(i, j, 2);
        }
    }
    out << "END1\n";
}

graphobserver::~graphobserver(){
    match->detach(this);
}
