//
//  solution.h
//  Implement_Trie
//
//  Created by 中央政治局常委 on 15/11/27.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; ++ i)
            node[i] = NULL;
    }
    TrieNode *node[26];
    bool isWord;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode * tmp = root;
        for (auto each:word) {
            if (!tmp->node[each -'a'])
                tmp->node[each -'a'] = new TrieNode();
            tmp = tmp->node[each - 'a'];
        }
        tmp->isWord = true;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *tmp = root;
        for (auto each:word) {
            if (!tmp->node[each - 'a'])
                return false;
            tmp = tmp->node[each - 'a'];
        }
        return tmp->isWord;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *tmp = root;
        for (auto each:prefix) {
            if (!tmp->node[each - 'a'])
                return false;
            tmp = tmp->node[each - 'a'];
        }
        return true;
    }
    
private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
#endif /* solution_h */
