//
//  main.cpp
//  3Sum_Closest
//
//  Created by 中央政治局常委 on 15/11/7.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    Solution test;
    vector<int> nums({0, 1, 2});
    test.threeSumClosest(nums, 0);
    return 0;
}
