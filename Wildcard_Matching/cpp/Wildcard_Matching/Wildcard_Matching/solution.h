//
//  solution.h
//  Wildcard_Matching
//
//  Created by 中央政治局常委 on 15/10/1.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return search(s, 0, p, 0);
    }
private:
    bool search(string &s, int posOfS, string p, int posOfP){
        while (p[posOfP] != '*') {
            if (p[posOfP] != '?' && s[posOfS] != p[posOfP]) return false;
            posOfP ++;
            posOfS ++;
            if (posOfS == s.size() && posOfP == p.size()) return true;
            if (posOfS != s.size() && posOfP == p.size()) return false;
        }
        int cntQuestionMark = 0;
        posOfP ++;
        while (posOfP != p.size() && (p[posOfP] == '*' || p[posOfP] == '?')) {
            cntQuestionMark += p[posOfP] == '?' ? 1 : 0;
            posOfP ++;
        }
        posOfS += cntQuestionMark;
        if (posOfS <= s.size() && posOfP == p.size()) return true;
        if (posOfS > s.size() && posOfP == p.size()) return false;
        if (posOfS + 1 > s.size()) return false;
        while (posOfS <= s.size()) {
            if (s[posOfS] == p[posOfP]) {
                if (search(s, posOfS + 1, p, posOfP + 1)) return true;
            }
            posOfS ++;
        }
        return false;
    }
};

#endif /* solution_h */
