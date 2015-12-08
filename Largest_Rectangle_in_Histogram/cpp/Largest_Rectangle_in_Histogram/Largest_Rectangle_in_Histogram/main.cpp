//
//  main.cpp
//  Largest_Rectangle_in_Histogram
//
//  Created by 中央政治局常委 on 15/12/6.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    Solution test;
    vector<int> nums({3,3,3,3,3,3,3,3,8,8,8,30,19});
    cout << test.largestRectangleArea(nums) << endl;
    return 0;
}
