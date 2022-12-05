#ifndef EVENTMGR_H
#define EVENTMGR_H

#include "trie.h"
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <utility>

class Game;

typedef void (Game::*callback)(void);

typedef void (Game::*callback2)(std::string);

class EventMgr {
    Trie t;
    std::unordered_map<std::string, callback> dispatch_table1;
    std::unordered_map<std::string, callback2> dispatch_table2;
    public:
        void register_command(std::string cmd, callback cb);
        void register_command(std::string cmd, callback2 cb2);
        void dispatch_command(std::string cmd, Game * instance);
        void dispatch_command(std::string cmd, Game * instance, std::string arg);
        std::pair<int, std::vector<std::string>> process_input();

};

#endif 
