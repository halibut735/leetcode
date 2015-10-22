//
//  main.cpp
//  Best_Time_to_Buy_and_Sell_Stock_IV
//
//  Created by 中央政治局常委 on 15/10/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include "solution.h"
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;

fstream handle("/Users/bingoboy/Downloads/cases.txt");
int main(int argc, const char * argv[]) {
    vector<int> prices;
    int tmp, k;
    Solution test;
    handle >> k;
    while (handle >> tmp) {
        prices.push_back(tmp);
    }
    cout << test.maxProfit(k, prices) << endl;
    
    return 0;
}
