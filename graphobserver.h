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
    Match* match;
    std::ostream &out = std::cout;

    std::vector<std::vector<char>>prevBoard1 = std::vector<std::vector<char>>(18, std::vector<char>(11, '.')); /* 18 rows * 11 cols */
    std::vector<std::vector<char>>prevBoard2 = std::vector<std::vector<char>>(18, std::vector<char>(11, '.')); /* 18 rows * 11 cols */
    int height = 840, width = 440*2 + 80, gap = 1;
    Xwindow * w;
    std::map<char, int> dict;

    public:
        ~graphobserver();
        graphobserver(Match* match);
            // studio{studio}, top{top}, bottom{bottom}, left{left}, right{right}{};
        void notify() override;
};

#endif
