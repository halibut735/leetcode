//
//  solution.h
//  Decode_Ways
//
//  Created by 中央政治局常委 on 15/11/11.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> cnts(s.size());
        if (s.empty()) return 0;
        cnts[0] = s[0] - '0' ? 1 : 0;
        if (!cnts[0] || s.size() == 1) return cnts[0];
        
        cnts[1] += isAdd(s[0], s[1]) ? 1 : 0;
        cnts[1] += s[1] - '0' ? cnts[0] : 0;
        if (!cnts[1]) return 0;
        
        for (int i = 2; i < s.size(); ++ i) {
            if (isZero(s[i -1], s[i])) return 0;
            cnts[i] += s[i] - '0' ? cnts[i - 1] : 0;
            cnts[i] += isAdd(s[i - 1], s[i]) ? cnts[i - 2] : 0;
        }
        return cnts[s.size() - 1];
    }
    
    inline bool isZero(char a, char b) {
        if (b == '0' && (a != '1' && a != '2')) return true;
        return false;
    }
    inline bool isAdd(char a, char b) {
        if (a == '1') return true;
        if (a == '2' && b < '7' && b >= '0') return true;
        return false;
    }
};
#endif /* solution_h */
