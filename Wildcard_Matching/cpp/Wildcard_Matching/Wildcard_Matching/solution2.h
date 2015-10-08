//
//  solution2.h
//  Wildcard_Matching
//
//  Created by 中央政治局常委 on 15/10/1.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution2_h
#define solution2_h
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        long pRecord = -1, sRecord = -1;
        long i, j;
        for (i = 0, j = 0; i < s.size();) {
            if (s[i] == p[j] || p[j] == '?') {
                i ++;
                j ++;
                continue;
            }
            if (p[j] == '*') {
                pRecord = j;
                j ++;
                sRecord = i;
                continue;
            }
            if (pRecord != -1) {
                j = pRecord + 1;
                i = sRecord ++;
                continue;
            }
            if (j == p.size() && i != s.size())  return false;
            return false;
        }
        while (j != p.size() && p[j] == '*') { ++ j;}
        if (j == p.size()) return true;
        return false;
    }
};


#endif /* solution2_h */
