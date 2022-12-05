#include "subject.h"
#include "observer.h"

void Subject::attach(Observer* o){
    observers.emplace_back(o);
    // std::cout << "Attatched" << std::endl;
}

void Subject::detach(Observer *o){
    for(auto it = observers.begin(); it != observers.end();++it){
        if (*it == o) observers.erase(it);
        break;
    }
}

void Subject::notifyObservers(int playerNum){
    for(auto ob: observers){
        std::cout << "asdf\n";
        ob->notify(playerNum);
    }
}

