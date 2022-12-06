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
        if (dispatch_table1.count(payload)) {
        func = dispatch_table1[payload];
        (instance->*func)();
        } else {
            for (auto &i : dispatch_table3[payload]) {
                (instance->*i)();
            }
        }
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

std::pair <int, std::vector<std::string>> EventMgr::fnp_input() {
    std::pair<int, std::vector<std::string>> ret;
    std::vector<std::string> bytes;
    std::string cmd;
    std::string arg = "";
    std::string arg2 = "";
    if (!((*in) >> cmd)) {
        if (in == &ifs) {
            ifs.close();
            in = &inp;
        }
        else {
            ret.first = 0;
            bytes.push_back("end");
            ret.second = bytes;
            return ret;
        }
        (*in) >> cmd;
    }
    std::istringstream iss{cmd};
    int pref = 1;
    std::string suff;
    if ('0' <= (iss.str())[0] && (iss.str())[0] <= '9') {
        iss >> pref;
    }
    iss >> suff;
    std::cout << suff << std::endl;
    suff = t.search(suff);
    if (suff == "macro") {
        (*in) >> arg;
        std::vector<callback> cblist;
        while(arg2 != "end") {
        (*in) >> arg2;
        std::string cmd_elem = t.search(arg2);
        if (cmd_elem != "" && cmd_elem != "end") {
            cblist.push_back(dispatch_table1[cmd_elem]);
        }
        }
        dispatch_table3[arg] = cblist;
        t.insert(arg);
        return fnp_input();
    }
    if (suff == "alias") {
        (*in) >> arg;
        (*in) >> arg2;
        dispatch_table1[arg2] = dispatch_table1[t.search(arg)];
        t.insert(arg2);
        return fnp_input();
    }
    if (suff == "sequence") {
        (*in) >> arg;
        ifs.open(arg, std::ifstream::in);
        in = &ifs;
        return fnp_input();
    }
    if (suff == "norandom") {
        (*in) >> arg;
    }
    bytes.push_back(suff);
    bytes.push_back(arg);
    ret.first = pref;
    ret.second = bytes;

    return ret;
}

std::pair<int, std::vector<std::string>> EventMgr::process_input() {
    
    return fnp_input();
}
