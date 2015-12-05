//
//  solution.h
//  Group_Anagrams
//
//  Created by 中央政治局常委 on 15/11/27.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<wordAttr, vector<int>> statistics;
        vector<vector<string>> ret;
        sort(strs.begin(), strs.end());
        for (int i = 0; i < strs.size(); ++ i) {
            wordAttr tmp;
            for (auto each:strs[i]) {
                tmp.alphabet[each - 'a'] ++;
            }
            statistics[tmp].push_back(i);
        }
        for (auto each:statistics) {
            vector<string> group;
            for (auto ele:each.second) {
                group.push_back(strs[ele]);
            }
            if (group.empty()) continue;
            ret.push_back(group);
        }
        return ret;
    }
private:
    struct wordAttr {
        int alphabet[26];
        wordAttr() {
            for (int i = 0; i < 26; ++ i)
                alphabet[i] = 0;
        }
        bool operator < (const wordAttr & a) const{
            for (int i = 0; i < 26; ++ i)
                if (alphabet[i] == a.alphabet[i]) continue;
                else return alphabet[i] < a.alphabet[i];
            return false;
        }
    };
};
#endif /* solution_h */
