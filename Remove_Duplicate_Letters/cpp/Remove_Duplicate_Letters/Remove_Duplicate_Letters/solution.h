//
//  solution.h
//  Remove_Duplicate_Letters
//
//  Created by 中央政治局常委 on 15/12/9.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> cnts;
        string ret;
        stack<char> stk;
        vector<bool> isVisited(26, false);
        for (char each : s) cnts[each] ++;
        for (int i = 0; i < s.size(); cnts[s[i]] --, ++ i) {
            if (isVisited[s[i] - 'a'] || (!stk.empty() && stk.top() == s[i])) continue;
            while (!stk.empty() && stk.top() > s[i] && cnts[stk.top()] > 0) {
                isVisited[stk.top() - 'a'] = false;
                stk.pop();
            }
            stk.push(s[i]);
            isVisited[s[i] - 'a'] = true;
        }
        while (!stk.empty()) {
            ret.push_back(stk.top());
            stk.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
#endif /* solution_h */
