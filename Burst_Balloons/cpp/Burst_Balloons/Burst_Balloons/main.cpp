//
//  main.cpp
//  Burst_Balloons
//
//  Created by 中央政治局常委 on 15/11/29.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    Solution test;
    vector<int> nums({35,16,83,87,84,59,48,41,20,54});
    cout << test.maxCoins(nums) << endl;
    return 0;
}
