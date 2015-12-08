//
//  main.cpp
//  Sliding_Window_Maximum
//
//  Created by 中央政治局常委 on 15/12/5.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution2.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> nums({1,3,1,2,0,5});
    Solution test;
    test.maxSlidingWindow(nums, 3);
    return 0;
}
