//
//  solution2.h
//  Shortest_Palindrome
//
//  Created by 中央政治局常委 on 15/10/3.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution2_h
#define solution2_h
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        string str, ret, revStr(s.rbegin(), s.rend());
        str = s + "#" + revStr;
        vector<long> next(str.size() + 1);
        next[0] = -1;
        long i = -1, j = 0;
        while (j <= str.size()) {
            if (i == -1 || str[i] == str[j])
                next[++ j] = ++ i;
            else
                i = next[i];
        }
        ret = revStr.substr(0, s.size() - next[str.size()]) + s;
        return ret;
    }
};

#endif /* solution2_h */
