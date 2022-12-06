#include "game.h"
#include "trie.h"
#include "textobserver.h"
#include "graphobserver.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <utility>
#include <vector>
#include <string>
#include "match.h"
#include "eventmgr.h"


int main(int argc, char* argv[]) {
    bool makeGraphics = true;
    int startLevel = 0;
    int randSeed = 0;
    std::string f1 = "sequence1.txt";
    std::string f2 = "sequence2.txt";
    //setting different booleans false or true depending on which commands are read
    if (argc > 1) {
        int index = 1;
        while (index < argc) {
            std::string cmd = argv[index];
            if (cmd == "-text") {
                makeGraphics = false;
            } else if (cmd == "-seed") {
                ++index;
                std::istringstream iss {cmd};
                iss >> randSeed;
            } else if (cmd == "-scriptfile1") {
                ++index;
                f1 = argv[index];
            } else if (cmd == "-scriptfile2") {
                ++index;
                f2 = argv[index];
            } else if (cmd == "-startlevel") {
                ++index;
                std::string arg = argv[index];
                std::istringstream iss {arg};
                iss >> startLevel;
            }
            ++index;
        }
    }
    Match m = {startLevel, f1, startLevel, f2}; //init match object
    srand(randSeed);
    std::unique_ptr<textobserver> t = std::make_unique<textobserver>(&m); //make textobserver
    std::unique_ptr<graphobserver> g;
    if (makeGraphics) {
        // make graphics observer
         g = std::make_unique<graphobserver>(&m);
    }
    //runs the game in an infinite loop
    while(m.playMatch()){}

}
