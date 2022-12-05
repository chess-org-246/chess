#ifndef EVENTMGR_H
#define EVENTMGR_H

#include "trie.h"
#include <unordered_map>

class Game;

typedef void (Game::*callback)(void);

class EventMgr {
    Trie t;
    std::unordered_map<std::string, callback> dispatch_table;
    public:
        void register_command(std::string cmd, callback cb);
        void dispatch_command(std::string cmd, Game * instance);

};

#endif 
