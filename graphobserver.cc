#include "graphobserver.h"


graphobserver::graphobserver(Match *match){
    this->match = match;
    this->w = new Xwindow(width, height);

    //creates a black background, places a white header at the top and creates a white vertical line down the middle, seperating the two boards
    w->fillRectangle(0, 0, width+100, height+100, 1);
    w->fillRectangle(0,0,width, 40, 0);
    w->fillRectangle(width/2-(40*gap),0, 40*gap, height, 0);

    
    w->fillRectangle(0, height-80, width, 80, 0); //creates a white footer at the bottom where the information goes
    w->drawString(width/2-40, 30, "BIQUADRIS"); //prints biquadris at the top of the screen
    w->drawString(width/4-40, 30, "PLAYER 1"); //prints player 1 and player 2 above each respective screen
    w->drawString(3*width/4, 30, "PLAYER 2");

    //prints Level at the bottom of each respective screen
    w->drawString(width/8-40, height-50, "Level: " + std::to_string(match->getLevel(1))); 
    w->drawString(5*width/8-40, height-50, "Level: " + std::to_string(match->getLevel(2)));

    //prints Next Block and creates a black space to show the block 
    w->drawString(2*width/8-40, height-50, "Next Block: ");
    w->fillRectangle(2*width/8-40+70, height-50-20, 60, 60, 1);

    w->drawString(6*width/8-40, height-50, "Next Block: ");
    w->fillRectangle(6*width/8-40+70, height-50-20, 60, 60, 1);
    
    //prints score
    w->drawString(width/8-40, height-20, "Score: " + std::to_string(match->getScore(1)));
    w->drawString(5*width/8-40, height-20, "Score: " + std::to_string(match->getScore(2)));

    match->attach(this); //attaches the observer to the subject
}

void graphobserver::notify(){
    if (match->getCurrPrompt() != "") {
        return;
    }
    //filling the dictionary with values
    dict['I'] = 5;
    dict['J'] = 4;
    dict['L'] = 8;
    dict['O'] = 6;
    dict['S'] = 3;
    dict['Z'] = 2;
    dict['T'] = 7;
    dict['.'] = 1;
    dict['?'] = 10;
    dict['*'] = 9;
    
    //gets the next block for player 1 and also finds the colour of said block
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
    //finds the next block of player 2 and finds the colour
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
    char c;//initalize the character that is read inside the double for loop
  
    //rewriting value of the level and score everytime a change happens
    w->drawString(width/8-40, height-50, "Level: " + std::to_string(match->getLevel(1)));
    w->drawString(5*width/8-40, height-50, "Level: " + std::to_string(match->getLevel(2)));
    w->drawString(width/8-40, height-20, "Score: " + std::to_string(match->getScore(1)));
    w->drawString(5*width/8-40, height-20, "Score: " + std::to_string(match->getScore(2)));
    
    // w->drawString(width/2-(40*gap), height-50, "High Score")
    //inside the next block box, we want to clear the previous blocks
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            w->fillRectangle((2*width/8-40+70)+i*15, (height-50-20)+j*15, 15, 15, 1);
            w->fillRectangle((6*width/8-40+70)+i*15, (height-50-20)+j*15, 15, 15, 1);
        }
    }
    //fill the next block box with the correct next block
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            if(temp1[j][i]){
                w->fillRectangle((2*width/8-40+70)+i*15, (height-50-20)+j*15, 15, 15, nextBlockColourP1);
            }
            if(temp2[j][i]){
                w->fillRectangle((6*width/8-40+70)+i*15, (height-50-20)+j*15, 15, 15, nextBlockColourP2);
            }
        }
    }
    //iterate through each square of the window aligning with each board
    for (int i = 0; i < height/40; ++i) {
        for (int j = 0; j < width/40; ++j) {

            if(i < 18 && j < 11){
                c = match->getState(i,j, 1); //if the index corresponds to the first board, fetch the char at that position
            }
            else if(i < 18 && j >= 11+gap && j < 11+gap+11){
                c = match->getState(i, j-12, 2); //if it corresponds to the second board, fetch the char at that position
            }
            else{
                c = '.'; //otherwise we fill most spots with an empty (.) value
            }
            int val = dict[c]; //fetch the colour of the char that was just set
            
            //if the char found is different from the char found previously at that position, then we want to recolour it
            if((i< 18) && (j < 11) && (match->getState(i, j, 1) != prevBoard1[i][j])){
                
                w->fillRectangle(j*40, i*40+40, 40, 40, val);
            }
            else if((i < 18) && (j >= 11+gap) && (j < 11+gap+11) && (match->getState(i, j-12, 2) != prevBoard2[i][j])){
                w->fillRectangle(j*40, i*40+40, 40, 40, val);
            }
        }
    }
    //after each change, update the previous board to the current one.
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
}

graphobserver::~graphobserver(){ //detach observer
    match->detach(this);
}
