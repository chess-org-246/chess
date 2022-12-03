#include "textobserver.h"

textobserver::textobserver(Game * game){
  this->game = game;
  game->attach(this);
}

void textobserver::notify(){
  out << "-------------------------" << std::endl;
    for(int i = 0; i < 18; i++) {
        out << "| ";
        for (int j = 0; j < 11; j++) {
            out << game->getState(i, j) << " ";
        }
        out << "|" << std::endl;
    }
    out << "-------------------------" << std::endl;
}


textobserver::~textobserver(){
  game->detach(this);
}
