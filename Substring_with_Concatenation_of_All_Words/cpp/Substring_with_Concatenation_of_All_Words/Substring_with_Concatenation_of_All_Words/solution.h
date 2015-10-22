//
//  solution.h
//  Substring_with_Concatenation_of_All_Words
//
//  Created by 中央政治局常委 on 15/10/21.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        unordered_map<string, int> cntWords;
        bool isAdded = false;
        if (words.empty() || s.size() < words.size() * words[0].size()) {
            return ret;
        }
        
        //initial the cntWords
        for (auto each:words) cntWords[each] ++;
        
        long lenOfAllWords =  words.size() * words[0].size();
        long wordLen = words[0].size();
        for (int i = 0; i < s.size() - lenOfAllWords + 1; ++ i) {
            int start = i;
            string word = s.substr(start, wordLen);
            while (cntWords.count(word)) {
                isAdded = true;
                if (-- cntWords[word] < 0) break;
                start += wordLen;
                if (start - i == lenOfAllWords) {
                    ret.push_back(i);
                    break;
                }
                word = s.substr(start, wordLen);
            }
            if (isAdded) {
                isAdded = false;
                for (auto each:words) cntWords[each] = 0;
                for (auto each:words) cntWords[each] ++;
            }
        }
        return ret;
    }
};
#endif /* solution_h */
