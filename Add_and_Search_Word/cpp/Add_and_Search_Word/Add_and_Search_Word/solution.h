//
//  solution.h
//  Add_and_Search_Word
//
//  Created by 中央政治局常委 on 15/11/10.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

struct trie{
    trie * node[26];
    bool isWord;
    
    trie():isWord(false){
        for (int i = 0; i < 26; ++ i)
            node[i] = 0;
    }
};


class WordDictionary {
public:
    trie *root;
    WordDictionary(){
         root = new trie();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        trie *tmp = root;
        for (auto each:word) {
            if (!tmp->node[each - 'a'])
                tmp->node[each - 'a'] = new trie();
            tmp = tmp->node[each - 'a'];
        }
        tmp->isWord = true;
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return ss(word, 0, root);
    }
    
    bool ss(string &word, int pos, trie * tmp) {
        if (pos == word.size()) return tmp->isWord;
        
        char chr = word[pos];
        if (chr == '.') {
            for (int i = 0; i < 26; ++ i) {
                if (tmp->node[i] && ss(word, pos + 1, tmp->node[i]))
                    return true;
            }
        }
        else {
            if (!tmp->node[chr - 'a']) return false;
            return ss(word, pos + 1, tmp->node[word[pos] - 'a']);
        }
        return false;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
#endif /* solution_h */
