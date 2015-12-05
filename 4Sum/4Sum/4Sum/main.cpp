//
//  main.cpp
//  4Sum
//
//  Created by 中央政治局常委 on 15/11/19.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
using namespace std;

fstream input("/Users/bingoboy/Desktop/in.txt");
fstream output("");
int main(int argc, const char * argv[]) {
    int target, tmp;
    Solution test;
    vector<int> nums;
    input >> target;
    while (input >> tmp) {
        nums.push_back(tmp);
    }
    auto haha = test.fourSum(nums, target);
    for (auto each:haha) {
        cout << each[0] << " " << each[1] << " " << each[2] << " " << each[3] << " " << endl;
    }
    return 0;
}
