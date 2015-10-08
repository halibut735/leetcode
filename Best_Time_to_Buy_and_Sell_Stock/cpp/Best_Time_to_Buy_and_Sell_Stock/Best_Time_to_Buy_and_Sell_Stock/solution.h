//
//  solution.h
//  Best_Time_to_Buy_and_Sell_Stock
//
//  Created by 中央政治局常委 on 15/10/7.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <fstream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int localMinPrice = -1, ret = 0;
        for (auto & each:prices) {
            localMinPrice = localMinPrice == -1 || localMinPrice > each ? each : localMinPrice;
            ret = each - localMinPrice > ret ? (each - localMinPrice) : ret;
        }
        if (ret == -1) return 0;
        return ret;
    }
};

#endif /* solution_h */
