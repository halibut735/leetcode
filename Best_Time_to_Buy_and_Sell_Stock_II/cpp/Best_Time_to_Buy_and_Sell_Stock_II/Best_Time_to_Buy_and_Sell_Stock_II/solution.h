//
//  solution.h
//  Best_Time_to_Buy_and_Sell_Stock_II
//
//  Created by 中央政治局常委 on 15/10/7.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int prePrice = prices[0], minPrice = prices[0], ret = 0;
        for (int i = 1; i <= prices.size(); ++ i) {
            if (i == prices.size() || prices[i] < prePrice) {
                ret += prePrice - minPrice;
                if (i != prices.size()) minPrice = prices[i];
            }
            prePrice = prices[i];
        }
        return ret;
    }
};

#endif /* solution_h */
