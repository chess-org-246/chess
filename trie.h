#ifndef TRIE_H
#define TRIE_H
 // PREFIX TRIE IMPLEMENTATION FOR INPUT
#include <unordered_map>
#include <memory>
#include <vector>
#include <string>


class Trie { //trie implementation
    std::vector<std::string> possibilities; // possible complete strings at node
    std::unordered_map<char, std::unique_ptr<Trie>> children;
    public:
    void insert(std::string s); 
    void insert_helper(std::string pre, std::string s);
    std::string search(std::string s);
    ~Trie();
};

#endif
