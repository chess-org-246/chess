#include "textobserver.h"

textobserver::textobserver(Match * match){
  this->match = match;
  match->attach(this);
}

void textobserver::notify(){
  // int offset = 0;
  // out << playerNum << std::endl;
  std::vector<std::vector<char>> player1Next = match->getNext(1);
  std::vector<std::vector<char>> player2Next = match->getNext(2);
  // if(playerNum == 2){
  //   offset = 12;
  // }
  out << std::setw(18);
  out << "        Player 1                   Player 2        " << std::endl;
  out << "Level:                 " << match->getLevel(1) << "   ";
  out << "Level:                 " << match->getLevel(2) << std::endl;

  out << "Score:                 " << match->getScore(1) << "   ";
  out << "Score:                 " << match->getScore(2) << std::endl;
  out << "-------------------------  -------------------------" << std::endl;
    for(int i = 0; i < 18; i++) {
        out << "| ";
        for (int j = 0; j < 11; j++) {
            out << match->getState(i, j, 1) << " ";
        }
        out << "|  ";

        out << "| ";
        for (int j = 0; j < 11; j++) {
            out << match->getState(i, j, 2) << " ";
        }
        out << "|" << std::endl;
    }

        
  out << "-------------------------  -------------------------" << std::endl;
  for(int i = 0;i<4;i++){
    for(int j = 0;j<4;j++){
      out << player1Next[i][j];
    }
    out << "\n";
  }
}


textobserver::~textobserver(){
  match->detach(this);
}
