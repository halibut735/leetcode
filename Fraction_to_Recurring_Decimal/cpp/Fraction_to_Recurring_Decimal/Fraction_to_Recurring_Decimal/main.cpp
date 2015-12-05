//
//  main.cpp
//  Fraction_to_Recurring_Decimal
//
//  Created by 中央政治局常委 on 15/11/16.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    Solution test;
    auto tmp = test.fractionToDecimal(-2147483648, 1);
    cout << tmp << endl;
    return 0;
}
