#ifndef TEXTOB_H
#define TEXTOB_H
#include <iomanip>  
#include <vector>
#include "observer.h"
#include "game.h"
#include "match.h"

//textobserver inhereits from Observer
class textobserver: public Observer{
    Match* match; //pointer to subject
    std::ostream &out = std::cout;

    public:
        ~textobserver();
        textobserver(Match * match); 
        void notify() override;
};

#endif
