#include "game.h"
#include "textobserver.h"
#include "graphobserver.h"
#include <iostream>


int main(/*int argc, char* argv[]*/) {
    std::vector<textobserver*> textstack;

    Game g1{1};
    textobserver* temp = new textobserver(&g1);
    textstack.emplace_back(temp);

    std::string command; 
    while(std::cin >> command) {
        if (command == "g") {
            g1.genBlock();
            g1.printBoard();
        } else if (command == "do") {
            g1.down();
            g1.printBoard();
        } else if (command == "dr") {
            g1.drop();
            g1.printBoard();
            g1.checkRows();
        } else if (command == "l") {
            g1.left();
            g1.printBoard();
        } else if (command == "r") {
            g1.right();
            g1.printBoard();
        } else if (command == "cw") {
            g1.rotate(false);
            g1.printBoard();
        } else if (command == "ccw") {
            g1.rotate(true);
            g1.printBoard();
        }
    }
    for(size_t i = 0;i<textstack.size();i++){
    delete textstack[i];
  }
}
