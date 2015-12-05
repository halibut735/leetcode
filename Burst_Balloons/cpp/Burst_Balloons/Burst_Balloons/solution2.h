//
//  solution2.h
//  Burst_Balloons
//
//  Created by 中央政治局常委 on 15/11/29.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution2_h
#define solution2_h
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        long len = nums.size();
        vector<vector<int>> dp(len + 2, vector<int>(len + 2));
        vector<int> balloons(1, 1);
        for (auto each : nums) if (each) balloons.push_back(each);
        balloons.push_back(1);
        len = balloons.size();
        burst(balloons, 0, len - 1, dp);
        return dp[0][len - 1];
    }
private:
    int burst(vector<int> &balloons, long x, long y, vector<vector<int>> &dp) {
        if (y == x + 1) return 0;
        if (dp[x][y]) return dp[x][y];
        int ans = 0;
        for (long i = x + 1; i < y; ++ i)
            ans = max(ans, burst(balloons, x, i, dp) + burst(balloons, i, y, dp) + balloons[x] * balloons[i] * balloons[y]);
        dp[x][y] = ans;
        return ans;
    }
};
#endif /* solution2_h */
