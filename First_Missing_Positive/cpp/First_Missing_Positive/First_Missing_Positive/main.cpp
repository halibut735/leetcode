//
//  main.cpp
//  First_Missing_Positive
//
//  Created by 中央政治局常委 on 15/12/7.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    Solution test;
    vector<int> nums({2,4,6,8,9,7,5,11,1,3,10});
    cout << test.firstMissingPositive(nums) << endl;
    return 0;
}
