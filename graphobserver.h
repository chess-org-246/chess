#ifndef GRAPHOB_H
#define GRAPHOB_H
#include <vector>
#include <map>

#include "window.h"
#include "game.h"
#include "observer.h"
#include "match.h"
#include "masks.h"
class graphobserver: public Observer{
    Match* match; //observers will have a pointer to the subject 
    std::ostream &out = std::cout; //alias cout as out to save time

    //we store the state of the boards in a double vector to allow for intelligent redrawing, if there
    //is a difference between the board stored in game and the state of the boards here, we can redraw the rectangle.
    std::vector<std::vector<char>>prevBoard1 = std::vector<std::vector<char>>(18, std::vector<char>(11, '.')); 
    std::vector<std::vector<char>>prevBoard2 = std::vector<std::vector<char>>(18, std::vector<char>(11, '.')); /* 18 rows * 11 cols */
    int height = 840, width = 440*2 + 80, gap = 1; //defining variables used in the graphic observer
    Xwindow * w;
    std::map<char, int> dict; //using a map with the types of blocks as keys and the number of the colour as a value

    public:
        ~graphobserver();
        graphobserver(Match* match); //initialize the window and the text on the windows as well as attaching the 
                                     //observer to the subject 
        void notify() override; //updates the graphical observer
};

#endif
