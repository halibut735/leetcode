//
//  solution.h
//  Best_Time_to_Buy_and_Sell_Stock_III
//
//  Created by 中央政治局常委 on 15/10/7.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        vector<int> leftProfit(prices.size(), 0);
        vector<int> rightProfit(prices.size(), 0);
        int minPrice = prices[0], maxDiff = 0, maxPrice = prices[prices.size() - 1], ret = 0;
        for (int i = 0; i < prices.size(); ++ i) {
            minPrice = prices[i] < minPrice ? prices[i] : minPrice;
            maxDiff = prices[i] - minPrice > maxDiff ? prices[i] - minPrice : maxDiff;
            leftProfit[i] = maxDiff;
        }
        maxDiff = 0;
        for (long i = prices.size() - 1; i >= 0; -- i) {
            maxPrice = prices[i] > maxPrice ? prices[i] : maxPrice;
            maxDiff = maxPrice - prices[i] > maxDiff ? maxPrice - prices[i] : maxDiff;
            rightProfit[i] = maxDiff;
        }
        rightProfit.push_back(0);
        for (int i = 0; i < prices.size(); ++ i) {
            ret = leftProfit[i] + rightProfit[i + 1] > ret ? leftProfit[i] + rightProfit[i + 1] : ret;
        }
        return ret;
    }
};
#endif /* solution_h */
