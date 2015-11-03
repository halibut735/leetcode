//
//  main.cpp
//  Single_Number_III
//
//  Created by 中央政治局常委 on 15/10/22.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

fstream handle("/Users/bingoboy/Downloads/cases.txt");
int main(int argc, const char * argv[]) {
    vector<int> nums;
    int tmp;
    Solution test;
    
    while (handle >> tmp) {
        nums.push_back(tmp);
    }
    
    test.singleNumber(nums);
    return 0;
}
