//
//  main.cpp
//  Find_the_Duplicate_Number
//
//  Created by 中央政治局常委 on 15/10/9.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "solution2.h"

int main(int argc, const char * argv[]) {
    vector<int> nums({1,1});
    Solution test;
    cout << test.findDuplicate(nums) << endl;
    return 0;
}
