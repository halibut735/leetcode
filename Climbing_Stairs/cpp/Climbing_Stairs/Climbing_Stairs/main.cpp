//
//  main.cpp
//  Climbing_Stairs
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int dp[2] = {1, 2};
        if (n <= 2) return dp[n - 1];
        for (int i = 2; i < n; ++ i) {
            dp[1] += dp[0];
            dp[0] = dp[1] - dp[0];
        }
        return dp[1];
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    sol.climbStairs(4);
    return 0;
}
