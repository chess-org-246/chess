#ifndef TRIE_H
#define TRIE_H

#include <unordered_map>
#include <vector>
#include <string>


class Trie {
    std::vector<std::string> possibilities;
    std::unordered_map<char, Trie*> children;
    public:
    void insert(std::string s); 
    void insert_helper(std::string pre, std::string s);
    std::string search(std::string s);
    ~Trie();
};

#endif