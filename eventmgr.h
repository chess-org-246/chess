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
    // input stream for cmd line
    std::istream &inp = std::cin;
    //input filestream if needed
    std::ifstream ifs;
    // pointer to istream for current input
    std::istream * in = &inp;
    // arg-less command dispatch_table
    std::unordered_map<std::string, callback> dispatch_table1;
    // unary argument command dispatch table
    std::unordered_map<std::string, callback2> dispatch_table2;
    // sequenced command dispatch table
    std::unordered_map<std::string, std::vector<callback>> dispatch_table3;
    public:
        // command to register a string as a command with a callback
        void register_command(std::string cmd, callback cb);
        // overloaded for unary arg functions
        void register_command(std::string cmd, callback2 cb2);
        // command to execute a given command from string
        void dispatch_command(std::string cmd, Game * instance);
        // overloaded for unary arg functions
        void dispatch_command(std::string cmd, Game * instance, std::string arg);
        // function to fetch and parse input from input streams
        std::pair<int, std::vector<std::string>> fnp_input();
        // function to grab a single spaced elimited string from input
        std::string fetch_byte();

};

#endif 
