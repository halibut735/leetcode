//
//  solution.h
//  Missing_Number
//
//  Created by 中央政治局常委 on 15/10/22.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long total = 0, sum = 0;
        total = nums.size() * (nums.size() + 1) / 2;
        for (auto each:nums)
            sum += each;
        return total - sum;
    }
};
#endif /* solution_h */
