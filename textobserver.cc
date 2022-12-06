#include "textobserver.h"

//init the textobserver
textobserver::textobserver(Match * match){
  this->match = match;
  match->attach(this);
}
 //print out each players board with their information
void textobserver::notify(){
  std::string gap = "            ";
  out << std::setw(18);
  out << "        Player 1          " + gap + "         Player 2        " << std::endl;
  out << "Level:                 " << match->getLevel(1) << gap ;
  out << "Level:                 " << match->getLevel(2) << std::endl;

  out << "Score:                 " << match->getScore(1) << gap;
  out << "Score:                 " << match->getScore(2) << std::endl;
  out << "-------------------------" + gap + "-------------------------" << std::endl;
    for(int i = 0; i < 18; i++) {
        out << "| ";
        for (int j = 0; j < 11; j++) {
            out << match->getState(i, j, 1) << " "; //get the state of each players board char by char
        }
        out << "|  ";

        out << "| ";
        for (int j = 0; j < 11; j++) {
            out << match->getState(i, j, 2) << " ";
        }
        out << "|" << std::endl;
    }

        
  out << "-------------------------"+gap+"-------------------------" << std::endl;
//find the next block
  std::vector<std::vector<int>> temp1;
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
    std::vector<std::vector<int>> temp2;
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
  out << "Next Block:                 " + gap + "Next Block:\n";
  for(int i = 0;i<4;i++){
    for(int j = 0;j<4;j++){
      if(temp1[i][j]){
        out << match->nextBlock(1);
      }
      else{
        out << ".";
      }
    }
    out << "                         " << gap;
    for(int j = 0;j<4;j++){
      if(temp2[i][j]){
        out << match->nextBlock(2);
      }
      else{
        out << ".";
      }
    }
    out << "\n";
  }
}


textobserver::~textobserver(){
  match->detach(this);
}
