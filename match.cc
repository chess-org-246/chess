#include "match.h"

Match::Match(int _p1Level, std::string f1, int _p2Level, std::string f2):
    highScore{0}, game1{std::make_unique<Game>(_p1Level, f1)}, game2{std::make_unique<Game>(_p1Level, f2)} {
        _p1Level = _p1Level;
        _p2Level = _p2Level;
        em.register_command("left", &Game::left);
        em.register_command("right", &Game::right);
        em.register_command("down", &Game::down);
        em.register_command("clockwise", &Game::rotateCW);
        em.register_command("counterclockwise", &Game::rotateCCW);
        em.register_command("drop", &Game::drop);
        em.register_command("levelup", &Game::levelUp);
        em.register_command("leveldown", &Game::levelDown); // TODO: add parameter for different players
        em.register_command("norandom", &Game::noRandom);
        em.register_command("random", &Game::random);
        em.register_command("sequence", (void (Game::*)(void)) nullptr);
        em.register_command("restart", (void (Game::*)(void)) nullptr);
        em.register_command("I", &Game::replaceI);
        em.register_command("J", &Game::replaceJ);
        em.register_command("L", &Game::replaceL);
        em.register_command("O", &Game::replaceO);
        em.register_command("S", &Game::replaceS);
        em.register_command("T", &Game::replaceT);
        em.register_command("Z", &Game::replaceZ);
}


bool Match::playMatch() {
    // this function is gonna have all the game logic

    std::cout << "biaquadriso" << std::endl;
    std::string cmd;
    if (std::cin >> cmd) { // start game
        bool run = true;
        bool p1 = true;
        game1->genBlock();
        while (run) {
            try {
                if (p1) {
                    game1->printBoard();
                    game2->printBoard();
                    game2->genBlock(); // generating OTHER player's block so they can see during their turn
                    // TODO something something to take input for game 1
                    bool p1turn = true;
                    while (p1turn) {
                        // take input
                        std::pair<int, std::vector<std::string>> input = em.process_input();
                        if (input.second[0] == "restart") {
                            restart();
                            return true;
                        }
                        for (int i = 0; i < input.first; ++i) {
                            if (input.second[0] == "leveldown") {
                                game1->levelDown("sequence1.txt");
                            } else {
                                if (input.second[1] != "") {
                                    em.dispatch_command(input.second[0], game1.get(), input.second[1]);
                                } else {
                                    em.dispatch_command(input.second[0], game1.get());
                                }
                            }
                        }
                        // apply both heavies
                        if (input.second[0] == "left" || input.second[0] == "right") {
                            bool result = game1->specialHeavy() && game1->levelHeavy();
                            if (!result) {
                                p1turn = false;
                            }
                        } else if (input.second[0] == "clockwise" || input.second[0] == "counterclockwise" || input.second[0] == "down") {
                            bool result = game1->levelHeavy();
                            if (!result) {
                                p1turn = false;
                            }
                        }
                        game1->printBoard();
                        if (input.second[0] == "drop") {
                            p1turn = false;
                        }
                    }
                    game1->constructiveForce(); // TODO constructive force
                    // TODO print everything using jeffrey's work
                    if (game1->getSpecial()) {
                        game1->setSpecial(false);
                        bool valid = false;
                        while (!valid) {
                            std::cout << "Choose your special action. (blind, heavy, force): ";
                            std::string cmd;
                            std::cin >> cmd;
                            if (cmd == "blind") {
                                valid = true;
                                game2->makeBlind();
                            } else if (cmd == "heavy") {
                                valid = true;
                                game2->makeHeavy();
                            } else if (cmd == "force") {
                                valid = true;
                                std::cout << "Enter the block you want to give your opponent: ";
                                std::cin >> cmd;
                                if (cmd == "I" || cmd == "i") {
                                    game2->replaceI();
                                } else if (cmd == "J" || cmd == "j") {
                                    game2->replaceJ();
                                } else if (cmd == "L" || cmd == "l") {
                                    game2->replaceL();
                                } else if (cmd == "O" || cmd == "o") {
                                    game2->replaceO();
                                } else if (cmd == "S" || cmd == "s") {
                                    game2->replaceS();
                                } else if (cmd == "T" || cmd == "t") {
                                    game2->replaceT();
                                } else if (cmd == "Z" || cmd == "z") {
                                    game2->replaceZ();
                                }
                            } else {
                                std::cout << "Invalid special action. Enter one of the above.";
                            }
                        }

                    }
                    game1->printBoard();

                } else {
                    game2->printBoard();
                    game1->genBlock(); // generating OTHER player's block so they can see during their turn
                    // TODO something something to take input for game 1
                    bool p2turn = true;
                    while (p2turn) {
                        // take input
                        std::pair<int, std::vector<std::string>> input = em.process_input();
                        if (input.second[0] == "restart") {
                            restart();
                            return true;
                        }
                        for (int i = 0; i < input.first; ++i) {
                            if (input.second[0] == "leveldown") {
                                game2->levelDown("sequence2.txt");
                            } else {
                                if (input.second[1] != "") {
                                    em.dispatch_command(input.second[0], game2.get(), input.second[1]);
                                } else {
                                    em.dispatch_command(input.second[0], game2.get());
                                }
                            }
                        }
                        // apply both heavies
                        if (input.second[0] == "left" || input.second[0] == "right") {
                            bool result = game2->specialHeavy() && game2->levelHeavy();
                            if (!result) {
                                p2turn = false;
                            }
                        } else if (input.second[0] == "clockwise" || input.second[0] == "counterclockwise" || input.second[0] == "down") {
                            bool result = game2->levelHeavy();
                            if (!result) {
                                p2turn = false;
                            }
                        }
                        game2->printBoard();
                        // if dropped, check level 4 counter if level 4
                        if (input.second[0] == "drop") {
                            p2turn = false;
                        }
                    }
                    game2->constructiveForce(); // TODO constructive force
                    // TODO print everything using jeffrey's work
                    if (game2->getSpecial()) {
                        game2->setSpecial(false);
                        bool valid = false;
                        while (!valid) {
                            std::cout << "Choose your special action. (blind, heavy, force): ";
                            std::string cmd;
                            std::cin >> cmd;
                            if (cmd == "blind") {
                                valid = true;
                                game1->makeBlind();
                            } else if (cmd == "heavy") {
                                valid = true;
                                game1->makeHeavy();
                            } else if (cmd == "force") {
                                valid = true;
                                std::cout << "Enter the block you want to give your opponent: ";
                                std::cin >> cmd;
                                if (cmd == "I" || cmd == "i") {
                                    game1->replaceI();
                                } else if (cmd == "J" || cmd == "j") {
                                    game1->replaceJ();
                                } else if (cmd == "L" || cmd == "l") {
                                    game1->replaceL();
                                } else if (cmd == "O" || cmd == "o") {
                                    game1->replaceO();
                                } else if (cmd == "S" || cmd == "s") {
                                    game1->replaceS();
                                } else if (cmd == "T" || cmd == "t") {
                                    game1->replaceT();
                                } else if (cmd == "Z" || cmd == "z") {
                                    game1->replaceZ();
                                }
                            } else {
                                std::cout << "Invalid special action. Enter one of the above.";
                            }
                        }

                    }
<<<<<<< HEAD
=======
                    game2->printBoard();
>>>>>>> 3e2e3ed (fixed specialblock generation and added restart)
                }
            } catch (NoSpaceForBlock) {
                run = false;
                if (p1) {
                    std::cout << "p2 lost\n";
                    // p2 lost
                } else {
                    std::cout << "p1 lost\n";
                    // p1 lost
                }
                if (game1->getScore() > highScore) {
                    highScore = game1->getScore();
                } 
                if (game2->getScore() > highScore) {
                    highScore = game2->getScore();
                }
                return false;
            }
            p1 = !p1;
        }
    }
    return false;
}

void Match::restart() {
    game1 = std::make_unique<Game>(game1->getLevel(), "sequence1.txt");
    game2 = std::make_unique<Game>(game2->getLevel(), "sequence2.txt");
}

