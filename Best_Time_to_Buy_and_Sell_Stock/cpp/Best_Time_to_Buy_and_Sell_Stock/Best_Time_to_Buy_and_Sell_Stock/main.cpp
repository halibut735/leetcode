//
//  main.cpp
//  Best_Time_to_Buy_and_Sell_Stock
//
//  Created by 中央政治局常委 on 15/10/7.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <string>
#include "solution.h"
#include <vector>
#include <fstream>
#include <unordered_map>
using namespace std;


fstream handle("/Users/bingoboy/Downloads/cases.txt");
int main(int argc, const char * argv[]) {
    Solution test;
    vector<int> prices;
    int tmp;
    while (handle >> tmp) {
        prices.push_back(tmp);
    }
    cout << test.maxProfit(prices) << endl;
    return 0;
}
