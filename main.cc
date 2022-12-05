#include "game.h"
#include "trie.h"
#include <iostream>
#include "eventmgr.h"


int main(/*int argc, char* argv[]*/) {
    Game g1{1};
    EventMgr e;
    e.register_command("left", &Game::left);
    e.register_command("right", &Game::right);
    e.register_command("down", &Game::down);
    e.register_command("clockwise", &Game::rotateCW);
    e.register_command("counterclockwise", &Game::rotateCCW);
    e.register_command("drop", &Game::drop);
    e.register_command("generate", &Game::genBlock);
    std::string command;
    while(std::cin >> command) {
        e.dispatch_command(command, &g1);
        g1.printBoard();
    }
    
/*
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
        } else if (command == "random") {
            g1.random();
        } else if (command == "norandom") {
            std::string f;
            std::cin >> f;
            std::cout << "norandom " << f << std::endl;
            g1.noRandom(f);
        }
    }
    */
}
