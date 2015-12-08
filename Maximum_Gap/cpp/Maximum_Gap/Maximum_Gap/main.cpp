//
//  main.cpp
//  Maximum_Gap
//
//  Created by 中央政治局常委 on 15/12/7.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main(int argc, const char * argv[]) {
    vector<int> nums({1,1,1,1,1,5,5,5,5,5});
    Solution test;
    cout << test.maximumGap(nums) << endl;
    return 0;
}
