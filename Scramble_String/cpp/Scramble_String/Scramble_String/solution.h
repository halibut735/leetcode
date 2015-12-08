//
//  solution.h
//  Scramble_String
//
//  Created by 中央政治局常委 on 15/12/7.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;



class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        int len = (int) s1.size();
        unordered_map<char, int> cnt;
        for (int i = 0; i < len; ++ i) {
            cnt[s1[i]] ++;
            cnt[s2[i]] --;
        }
        for (auto each : cnt)
            if (each.second) return false;
        for (int i = 1; i < len; ++ i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i)))
                return true;
        }
        return false;
    }
};



#endif /* solution_h */
