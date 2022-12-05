#include "match.h"

<<<<<<< HEAD
Match::Match(int _p1Level, int _p2Level):
    highScore{0}, game1{_p1Level}, game2{_p2Level} {
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
        //em.register_command("restart", &Match::restart);
        em.register_command("I", &Game::replaceI);
        em.register_command("J", &Game::replaceJ);
        em.register_command("L", &Game::replaceL);
        em.register_command("O", &Game::replaceO);
        em.register_command("S", &Game::replaceS);
        em.register_command("T", &Game::replaceT);
        em.register_command("Z", &Game::replaceZ);
=======
Match::Match(int p1Level, int p2Level) : highScore{0}, game1{p1Level}, game2{p2Level}
{
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
    /*em.register_command("sequence", &Game::sequence);
    em.register_command("I", &Game::restart);
    em.register_command("J", &Game::restart);
    em.register_command("L", &Game::restart);
    em.register_command("O", &Game::restart);
    em.register_command("S", &Game::restart);
    em.register_command("Z", &Game::restart);
    em.register_command("T", &Game::restart);*/
>>>>>>> 46a439e (side by side observers)
}

void Match::playMatch()
{
    // this function is gonna have all the game logic

    std::cout << "biaquadriso" << std::endl;
    std::string cmd;
    if (std::cin >> cmd)
    { // start game
    std::cout << "started\n";
        bool run = true;
        bool p1 = true;
        game1.genBlock();
        while (run)
        {
            try
            {
                if (p1)
                {
                    // game1.printBoard();
                    std::cout << "ABOVW\n";
                    this->printBoard(1);
                    std::cout << "BELOW\n";
                    game2.genBlock(); // generating OTHER player's block so they can see during their turn
                    // TODO something something to take input for game 1
                    bool p1turn = true;
                    while (p1turn)
                    {
                        // take input
                        std::cout << "p1 level: " << game1.getLevel() << std::endl;
                        std::pair<int, std::vector<std::string>> input = em.process_input();
<<<<<<< HEAD
                        for (int i = 0; i < input.first; ++i) {
                            if (input.second[0] == "leveldown") {
                                game1.levelDown("sequence1.txt");
                            } else {
                                if (input.second[1] != "") {
                                    em.dispatch_command(input.second[0], &game1, input.second[1]);
                                } else {
                                    em.dispatch_command(input.second[0], &game1);
                                }
=======
                        for (int i = 0; i < input.first; ++i)
                        {
                            if (input.second[1] != "")
                            {
                                em.dispatch_command(input.second[0], &game1, input.second[1]);
                            }
                            else
                            {
                                em.dispatch_command(input.second[0], &game1);
>>>>>>> 46a439e (side by side observers)
                            }
                        }
                        // apply both heavies
                        if (input.second[0] == "left" || input.second[0] == "right")
                        {
                            bool result = game1.specialHeavy() && game1.levelHeavy();
                            if (!result)
                            {
                                p1turn = false;
                            }
                        }
                        else if (input.second[0] == "clockwise" || input.second[0] == "counterclockwise" || input.second[0] == "down")
                        {
                            bool result = game1.levelHeavy();
                            if (!result)
                            {
                                p1turn = false;
                            }
                        }
                        // game1.printBoard();
                        this->printBoard(1);
                        if (input.second[0] == "drop")
                        {
                            p1turn = false;
                        }
                    }
                    game1.constructiveForce(); // TODO constructive force
                    // TODO print everything using jeffrey's work
<<<<<<< HEAD
                    if (game1.getSpecial()) {
                        game1.setSpecial(false);
                        bool valid = false;
                        while (!valid) {
                            std::cout << "Choose your special action. (blind, heavy, force): ";
                            std::string cmd;
                            std::cin >> cmd;
                            if (cmd == "blind") {
                                valid = true;
                                //game2.makeBlind();
                            } else if (cmd == "heavy") {
                                valid = true;
                                //game2.makeHeavy();
                            } else if (cmd == "force") {
                                valid = true;
                            } else {
                                std::cout << "Invalid special action. Enter one of the above.";
                            }
                        }

                    }
                    game1.printBoard();

                } else {
                    game2.printBoard();
=======
                    // game1.printBoard();
                    this->printBoard(1);
                }
                else
                {
                    // game2.printBoard();
                    this->printBoard(2);
>>>>>>> 46a439e (side by side observers)
                    game1.genBlock(); // generating OTHER player's block so they can see during their turn
                    // TODO something something to take input for game 1
                    bool p2turn = true;
                    while (p2turn)
                    {
                        // take input
                        std::cout << "p2 level: " << game2.getLevel() << std::endl;
                        std::pair<int, std::vector<std::string>> input = em.process_input();
<<<<<<< HEAD
                        for (int i = 0; i < input.first; ++i) {
                            if (input.second[0] == "leveldown") {
                                game2.levelDown("sequence2.txt");
                            } else {
                                if (input.second[1] != "") {
                                    em.dispatch_command(input.second[0], &game2, input.second[1]);
                                } else {
                                    em.dispatch_command(input.second[0], &game2);
                                }
=======
                        for (int i = 0; i < input.first; ++i)
                        {
                            if (input.second[1] != "")
                            {
                                em.dispatch_command(input.second[0], &game2, input.second[1]);
                            }
                            else
                            {
                                em.dispatch_command(input.second[0], &game2);
>>>>>>> 46a439e (side by side observers)
                            }
                        }
                        // apply both heavies
                        if (input.second[0] == "left" || input.second[0] == "right")
                        {
                            bool result = game2.specialHeavy() && game2.levelHeavy();
                            if (!result)
                            {
                                p2turn = false;
                            }
                        }
                        else if (input.second[0] == "clockwise" || input.second[0] == "counterclockwise" || input.second[0] == "down")
                        {
                            bool result = game2.levelHeavy();
                            if (!result)
                            {
                                p2turn = false;
                            }
                        }
                        // game2.printBoard();
                        this->printBoard(2);
                        // if dropped, check level 4 counter if level 4
                        if (input.second[0] == "drop")
                        {
                            p2turn = false;
                        }
                    }
                    game2.constructiveForce(); // TODO constructive force
                    // TODO print everything using jeffrey's work
                    // game2.printBoard();
                    this->printBoard(2);
                }
            }
            catch (NoSpaceForBlock)
            {
                run = false;
                if (p1)
                {
                    std::cout << "p1 lost\n";
                    // p1 lost
                }
                else
                {
                    std::cout << "p2 lost\n";
                    // p2 lost
                }
                if (game1.getScore() > highScore)
                {
                    highScore = game1.getScore();
                }
                if (game2.getScore() > highScore)
                {
                    highScore = game2.getScore();
                }
                break;
            }
            p1 = !p1;
        }
    }
}

<<<<<<< HEAD
void Match::restart() {
    game1 = {0, "sequence1.txt"};
    game2 = {0, "sequence1.txt"};
}

=======
char Match::getState(int row, int col) const
{
    if (col >= 12)
    {
        return game2.getState(row, col - 12);
    }
    else if (col < 11)
    {
        return game1.getState(row, col);
    }
    return '.';
}

char Match::getPrevState(int row, int col) const
{
    if (col >= 12)
    {
        return game2.getPrevState(row, col - 12);
    }
    else if (col < 11)
    {
        return game1.getPrevState(row, col);
    }
    return '.';
}

void Match::printBoard(int playerNum){
    this->notifyObservers(playerNum);
}
>>>>>>> 46a439e (side by side observers)
