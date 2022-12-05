#include "textobserver.h"

textobserver::textobserver(Match * match){
  this->match = match;
  match->attach(this);
}

void textobserver::notify(int playerNum){
  // int offset = 0;
  out << playerNum << std::endl;
  // if(playerNum == 2){
  //   offset = 12;
  // }

  out << "        Player 1                    Player 2        " << std::endl;
  out << "Level:               " <<   match.game1.getLevel() << "  Level:                   " << match.game2.getLevel() << std::endl; 
  out << "-------------------------  -------------------------" << std::endl;
    for(int i = 0; i < 18; i++) {
        out << "| ";
        for (int j = 0; j < 11; j++) {
            out << match->getState(i, j) << " ";
        }
        out << "|  ";

        out << "| ";
        for (int j = 0; j < 11; j++) {
            out << match->getState(i, j+12) << " ";
        }
        out << "|" << std::endl;
    }

        
  out << "-------------------------  -------------------------" << std::endl;
  out << ""
}


textobserver::~textobserver(){
  match->detach(this);
}
