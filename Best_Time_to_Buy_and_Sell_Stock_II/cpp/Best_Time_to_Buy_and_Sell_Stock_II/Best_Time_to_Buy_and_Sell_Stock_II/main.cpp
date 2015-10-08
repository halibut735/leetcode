//
//  main.cpp
//  Best_Time_to_Buy_and_Sell_Stock_II
//
//  Created by 中央政治局常委 on 15/10/7.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
using namespace std;
#include "solution.h"

fstream handle("/Users/bingoboy/Downloads/cases.txt");
int main(int argc, const char * argv[]) {
    Solution test;
    int tmp;
    vector<int> prices;
    while (handle >> tmp) {
        prices.push_back(tmp);
    }
    cout << test.maxProfit(prices) << endl;
    return 0;
}
