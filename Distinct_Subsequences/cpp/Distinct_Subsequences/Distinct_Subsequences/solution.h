//
//  solution.h
//  Distinct_Subsequences
//
//  Created by 中央政治局常委 on 15/12/3.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int lens = s.size(), lent = t.size();
        if (s.size() < t.size()) return 0;
        vector<vector<int>> dp(lens, vector<int>(lent, 0));
        for (int i = 0; i < lens; ++ i) dp[i][0] = (i ? dp[i - 1][0] : 0) + (s[i] == t[0] ? 1 : 0);
        for (int i = 1; i < lens; ++ i) {
            for (int j = 1; j < lent; ++ j) {
                dp[i][j] = dp[i - 1][j];
                if (t[j] == s[i])  dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp[lens - 1][lent - 1];
    }
};

#endif /* solution_h */
