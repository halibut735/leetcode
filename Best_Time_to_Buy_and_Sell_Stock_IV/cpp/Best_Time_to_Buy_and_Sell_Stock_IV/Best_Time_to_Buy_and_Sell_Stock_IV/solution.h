//
//  solution.h
//  Best_Time_to_Buy_and_Sell_Stock_IV
//
//  Created by 中央政治局常委 on 15/10/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2 || k == 0) return 0;
        if (k >= prices.size() / 2){
            int nolimitedProfit = 0, diff = 0;
            for (int i = 1; i < prices.size(); ++ i) {
                diff = prices[i] - prices[i - 1];
                nolimitedProfit += diff > 0 ? diff : 0;
            }
            return nolimitedProfit;
        }
        
        
        vector<int> sell(k + 1);
        vector<int> buy(k + 1, INT_MIN);
        for (int i = 0; i < prices.size(); ++ i) {
            for (int j = 1; j <= k; ++ j) {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(buy[j] + prices[i], sell[j]);
            }
        }
        return sell[k];
    }
};
#endif /* solution_h */
