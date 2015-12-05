//
//  main.cpp
//  Minimum_Size_Subarray_Sum
//
//  Created by 中央政治局常委 on 15/11/27.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <set>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> nums({2,3,1,2,4,1});
    Solution test;
    cout << test.minSubArrayLen(7, nums) << endl;
    return 0;
}
