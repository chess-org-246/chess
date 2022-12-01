#include "match.h"

Match::Match():
    high_score_1{0}, high_score_2{0}, game_1{}, game_2{}, input{} {}

Match::playMatch() {
    // this function is gonna have all the game logic
    bool startMenu = true;

    while (startMenu) {
        // use the input/output class to print a prompt
        // any character to start
        std::string cmd;
        if (std::cin >> cmd) {
            game_1.level->generateBlock(); // create the first blocks
            game_2.level->generateBlock();
        }
    }
}
