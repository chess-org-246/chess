#include "match.h"

Match::Match(int p1Level, int p2Level):
    highScore{0}, game1{p1Level}, game2{p2Level} {
        e.register_command("left", &Game::left);
        e.register_command("right", &Game::right);
        e.register_command("down", &Game::down);
        e.register_command("clockwise", &Game::rotateCW);
        e.register_command("counterclockwise", &Game::rotateCCW);
        e.register_command("drop", &Game::drop);
        e.register_command("levelup", &Game::levelUp);
        e.register_command("leveldown", &Game::levelDown); // TODO: add parameter for different players
        e.register_command("norandom", &Game::noRandom);
        e.register_command("random", &Game::random);
        /*e.register_command("sequence", &Game::sequence);
        e.register_command("I", &Game::restart);
        e.register_command("J", &Game::restart);
        e.register_command("L", &Game::restart);
        e.register_command("O", &Game::restart);
        e.register_command("S", &Game::restart);
        e.register_command("Z", &Game::restart);
        e.register_command("T", &Game::restart);*/
}

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
                        bool p1turn = true;
                        while (p1turn) {
                            // take input
                            std::pair<int, std::vector<string>> input = em.process_input();
                            for (int i = 0; i < input.first; ++i) {
                                if (input.second[1] != "") {
                                    em.dispatch_command(input.second[0], &game1, input.second[1]);
                                } else {
                                    em.dispatch_command(input.second[0], &game1);
                                }
                            }
                            // apply both heavies
                            if (input.second[0] == "left" || input.second[0] == "right") {
                                bool result == g1.specialHeavy() && g1.levelHeavy();
                                if (!result) {
                                    p1turn = false;
                                }
                            } else if (input.second[0] == "clockwise" || input.second == "counterclockwise" || input.second[0] == "down") {
                                bool result = game1.levelHeavy();
                                if (!result) {
                                    p1turn = false;
                                }
                            }
                            // if dropped, check level 4 counter if level 4
                        }
                        game1.constructiveForce(); // TODO constructive force
                        // TODO print everything using jeffrey's work
                    } else {
                        game1.level->generateBlock(); // generating OTHER player's block so they can see during their turn
                        // TODO something something to take input for game 1
                        bool p2turn = true;
                        while (p2turn) {
                            // take input
                            std::pair<int, std::vector<string>> input = em.process_input();
                            for (int i = 0; i < input.first; ++i) {
                                if (input.second[1] != "") {
                                    em.dispatch_command(input.second[0], &game2, input.second[1]);
                                } else {
                                    em.dispatch_command(input.second[0], &game2);
                                }
                            }
                            // apply both heavies
                            if (input.second[0] == "left" || input.second[0] == "right") {
                                bool result == game2.specialHeavy() && game2.levelHeavy();
                                if (!result) {
                                    p2turn = false;
                                }
                            } else if (input.second[0] == "clockwise" || input.second == "counterclockwise" || input.second[0] == "down") {
                                bool result = game2.levelHeavy();
                                if (!result) {
                                    p2turn = false;
                                }
                            }
                            // if dropped, check level 4 counter if level 4
                        }
                        game2.constructiveForce(); // TODO constructive force
                        // TODO print everything using jeffrey's work
                    }
                } catch (NoSpaceForBlock) {
                    run = false;
                    if (p1) {
                        // p1 lost
                    } else {
                        // p2 lost
                    }
                    if (game1.getScore() > highScore) {
                        highScore == game1.getScore();
                    } 
                    if (game2.getScore() > highScore) {
                        highScore == game2.getScore();
                    }
                }
                p1 = !p1;
            }
        }
    }
}
