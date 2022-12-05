#include "match.h"

Match::Match(int p1Level, int p2Level):
    highScore{0}, game1{p1Level}, game2{p2Level} {}

Match::playMatch() {
    // this function is gonna have all the game logic
    bool startMenu = true;

    while (startMenu) {
        // use the input/output class to print a prompt
        // any character to start
        
        // TODO: print start menu 

        std::string cmd;
        if (std::cin >> cmd) { // start game
            bool run = true;
            bool p1 = true;
            game1.level->generateBlock();
            
            while (run) {
                try {
                    if (p1) {
                        game2.level->generateBlock(); // generating OTHER player's block so they can see during their turn
                        // TODO something something to take input for game 1
                        // run game 1's commands
                        /* if heavy & command was left or right
                            int prevt = game1.getT();
                            game1.down();
                            game1.down();
                            if (game1.getT() != prevt + 2) {
                                game1.drop();
                            }*/
                        // if dropped, check level 4 counter if level 4
                    } else {
                        game1.level->generateBlock();
                        // TODO game 2's input
                        // game 2's commands
                        /* if heavy & command was left or right
                            int prevt = game1.getT();
                            game2.down();
                            game2.down();
                            if (game2.getT() != prevt + 2) {
                                game2.drop();
                            }*/
                        // if dropped, check level 4 counter if level 4
                    }
                } catch (NoSpaceForBlock) {
                    run = false;
                    if (p1) {
                        // p1 lost
                    } else {
                        // p2 lost
                    }
                    // update high scores
                }
                p1 = !p1;
            }
        }
    }
}
