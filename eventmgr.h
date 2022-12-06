#ifndef EVENTMGR_H
#define EVENTMGR_H

#include "trie.h"
#include <unordered_map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <utility>

class Game;

typedef void (Game::*callback)(void);

typedef void (Game::*callback2)(std::string);

class EventMgr {
    Trie t;
    
    std::istream &inp = std::cin;
    std::ifstream ifs;

    std::istream * in = &inp;

    std::unordered_map<std::string, callback> dispatch_table1;
    std::unordered_map<std::string, callback2> dispatch_table2;
    std::unordered_map<std::string, std::vector<callback>> dispatch_table3;
    public:
        void register_command(std::string cmd, callback cb);
        void register_command(std::string cmd, callback2 cb2);
        void dispatch_command(std::string cmd, Game * instance);
        void dispatch_command(std::string cmd, Game * instance, std::string arg);
        std::pair<int, std::vector<std::string>> fnp_input();
        std::pair<int, std::vector<std::string>> process_input();

};

#endif 
