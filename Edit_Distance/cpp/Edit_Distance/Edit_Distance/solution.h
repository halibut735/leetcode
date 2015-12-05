//
//  solution.h
//  Edit_Distance
//
//  Created by 中央政治局常委 on 15/12/5.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;



class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size(), rep = 0, delins = 0;
        if (word1.empty() || word2.empty()) return len1 | len2;
        vector<vector<int>> dp(len1, vector<int>(len2, -1));
        dp[0][0] = word1[0] == word2[0] ? 0 : 1;
        for (int i = 1; i < len1; ++ i) dp[i][0] = word1[i] == word2[0] ? i : dp[i - 1][0] + 1;
        for (int i = 1; i < len2; ++ i) dp[0][i] = word1[0] == word2[i] ? i : dp[0][i - 1] + 1;
        for (int i = 1; i < len1; ++ i) {
            for (int j = 1; j < len2; ++ j) {
                rep = word1[i] == word2[j] ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1;
                delins = min(dp[i - 1][j], dp[i][j - 1]) + 1;
                dp[i][j] = min(rep, delins);
            }
        }
        return dp[len1 - 1][len2 - 1];
    }
};


#endif /* solution_h */
