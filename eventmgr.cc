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
        if (dispatch_table1.count(payload)) { // if command is an argless cmd, execute
        func = dispatch_table1[payload];
        (instance->*func)();
        } else { // otherwise if command is a macro, execute all
            for (auto &i : dispatch_table3[payload]) {
                (instance->*i)();
            }
        }
    }
}

void EventMgr::dispatch_command(std::string cmd, Game * instance, std::string arg) {
    callback2 func2;
    std::string payload = t.search(cmd);
    if (payload != "") { // if command exists, execute with arg
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
    if (!((*in) >> cmd)) { // if input is ended
        if (in == &ifs) { // if currently using file input, return to regular input
            ifs.close();
            in = &inp;
        }
        else { // otherwise, return end flag for match
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
    if ('0' <= (iss.str())[0] && (iss.str())[0] <= '9') { // if first letter is a number
        iss >> pref; // grab prefix int
    }
    iss >> suff;
    suff = t.search(suff); // search for full command in trie
    if (suff == "macro") { // if macro, initialize sequence in table
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
    if (suff == "alias") { // if alias, insert alias into table
        (*in) >> arg;
        (*in) >> arg2;
        dispatch_table1[arg2] = dispatch_table1[t.search(arg)];
        t.insert(arg2);
        return fnp_input();
    }
    if (suff == "sequence") { // if sequenece, set input source to filestream
        (*in) >> arg;
        ifs.open(arg, std::ifstream::in);
        in = &ifs;
        return fnp_input();
    }
    if (suff == "norandom") { // if norandom, grab argument and return;
        (*in) >> arg;
    }
    bytes.push_back(suff);
    bytes.push_back(arg);
    ret.first = pref;
    ret.second = bytes;

    return ret;
}
