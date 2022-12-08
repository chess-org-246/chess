#include "trie.h"
#include <iostream>
void Trie::insert(std::string s) {
    insert_helper(s, s);
}

void Trie::insert_helper(std::string pre, std::string s) {
    possibilities.push_back(s);
    if (pre == "") {
        return;
    }
    if(children.count(pre[0])) {
        children[pre[0]]->insert_helper(pre.substr(1), s);
    }
    else {
        children[pre[0]] = std::make_unique<Trie>();
        children[pre[0]]->insert_helper(pre.substr(1), s);
    }
}

std::string Trie::search(std::string s) {
    if (s == "") {
        if (possibilities.size() == 1) {
            return possibilities[0];
        }
        else {
            return "";
        }
    }
    else {
    if(children.count(s[0])) {
        return children[s[0]]->search(s.substr(1));
    }
    else {
        return "";
    }
    }
}

Trie::~Trie() {
}



