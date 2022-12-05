#include "eventmgr.h"
void EventMgr::register_command(std::string cmd, callback cb) {
    t.insert(cmd);
    dispatch_table1[cmd] = cb;
}

void EventMgr::register_command(std::string cmd, callback2 cb2) {
    t.insert(cmd);
    dispatch_table2[cmd] = cb2;
}


void EventMgr::dispatch_command(std::string cmd, Game * instance) {
    callback func;
    std::string payload = t.search(cmd);
    if (payload != "") {
        func = dispatch_table1[payload];
        (instance->*func)();
    }
}

void EventMgr::dispatch_command(std::string cmd, Game * instance, std::string arg) {
    callback2 func2;
    std::string payload = t.search(cmd);
    if (payload != "") {
        func2 = dispatch_table2[payload];
        (instance->*func2)(arg);
    }
}

std::pair<int, std::vector<std::string>> EventMgr::process_input() {
    std::pair<int, std::vector<std::string>> ret;
    std::vector<std::string> bytes;
    std::string cmd;
    std::string arg = "";
    std::cin >> cmd;
    std::istringstream iss{cmd};
    int pref = 1;
    std::string suff;
    if ('0' <= (iss.str())[0] && (iss.str())[0] <= '9') {
        iss >> pref;
    }
    iss >> suff;
    std::cout << suff << std::endl;
    suff = t.search(suff);
    if (t.search(suff) == "norandom" || t.search(suff) == "sequence") {
        std::cin >> arg;
    }
    bytes.push_back(suff);
    bytes.push_back(arg);
    ret.first = pref;
    ret.second = bytes;
    return ret;
}
