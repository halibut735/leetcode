//
//  solution.h
//  Minimum_Window_Substring
//
//  Created by 中央政治局常委 on 15/10/6.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <fstream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, queue<long>> chrPos;
        set<long> postions;
        long maxIndex = -1, minIndex = -1;
        for (auto each:t)
            chrPos[each].push(-1);
        
        for (int i = 0; i < s.size(); ++ i) {
            if (!chrPos.count(s[i]))
                continue;
            long tmp = chrPos[s[i]].front();
            chrPos[s[i]].pop();
            chrPos[s[i]].push(i);
            if (postions.count(tmp))
                postions.erase(postions.find(tmp));
            postions.emplace(i);
            if (postions.size() == t.size() &&
                (maxIndex == -1 || minIndex == -1 ||
                 (*postions.rbegin() - *postions.begin() < maxIndex - minIndex))) {
                maxIndex = *postions.rbegin();
                minIndex = *postions.begin();
            }
        }
        if (minIndex == -1 || maxIndex == -1) return "";
        return s.substr(minIndex, maxIndex - minIndex + 1);
    }
};
#endif /* solution_h */
