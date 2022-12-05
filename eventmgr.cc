#include "eventmgr.h"
#include <iostream>
void EventMgr::register_command(std::string cmd, callback cb) {
    t.insert(cmd);
    dispatch_table[cmd] = cb;
}

void EventMgr::dispatch_command(std::string cmd, Game * instance) {
    callback func;
    std::string payload = t.search(cmd);
    std::cout << payload << std::endl;
    if (payload != "") {
        func = dispatch_table[payload];
        (instance->*func)();
    }

}