//
//  solution.h
//  Palindrome_Partitioning_II
//
//  Created by 中央政治局常委 on 15/10/21.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int len = (int) s.size();
        vector<int> dp(len, len + 100);
        vector<vector<bool>> isParlin(len, vector<bool>(len, false));
        dp[0] = 0;
        for (int j = 0; j < len; ++ j) {
             for (int i = j; i >= 0; -- i) {
                 if (s[i] == s[j] && (j - i < 3 || isParlin[i + 1][j - 1])) {
                     isParlin[i][j] = true;
                     dp[j] = min(dp[j], i ? (dp[i - 1] + 1) : 0);
                 }
            }
        }
        return dp[len - 1];
    }
};
#endif /* solution_h */
