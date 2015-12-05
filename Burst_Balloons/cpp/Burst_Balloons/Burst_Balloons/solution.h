//
//  solution.h
//  Burst_Balloons
//
//  Created by 中央政治局常委 on 15/11/29.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
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
        vector<vector<int>> dp(len + 2, vector<int>(len + 2, 0));
        vector<int> balloons(1, 1);
        for (auto each : nums) if (each) balloons.push_back(each);
        balloons.push_back(1);
        len = balloons.size();
        
        for (int i = 2; i < len; ++ i) {
            for (int left = 0; left + i < len; ++ left) {
                int right = left + i;
                for (int k = left + 1; k < right; ++ k) {
                    dp[left][right] = max(dp[left][right], balloons[left] * balloons[k] * balloons[right] + dp[left][k] + dp[k][right]);
                }
            }
        }
        
        return dp[0][len - 1];
    }
};
#endif /* solution_h */
