//
//  main.cpp
//  Coin_Change
//
//  Created by 中央政治局常委 on 15/12/27.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i <= amount; ++ i) {
            for (int j = 0; j < coins.size(); ++ j) {
                if (i - coins[j] >= 0) dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main(int argc, const char * argv[]) {
    vector<int> coins({1,2,5});
    Solution test;
    cout << test.coinChange(coins, 11) << endl;
    return 0;
}
