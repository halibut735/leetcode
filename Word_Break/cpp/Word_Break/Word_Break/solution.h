//
//  solution.h
//  Word_Break
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
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<long> breakPoint(1, -1);
        string subStr;
        long lastPos = 0;
        for (int i = 0; i < s.size(); ++ i) {
            for (auto it = breakPoint.rbegin(); it != breakPoint.rend(); ++it) {
                lastPos = *it;
                subStr = s.substr(lastPos + 1, i - lastPos);
                if (wordDict.count(subStr)) {
                    breakPoint.push_back(i);
                    break;
                }
            }
        }
        return breakPoint.back() == (s.size() - 1);
    }
};

#endif /* solution_h */
