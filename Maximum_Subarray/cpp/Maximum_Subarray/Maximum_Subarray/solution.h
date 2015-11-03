//
//  solution.h
//  Maximum_Subarray
//
//  Created by 中央政治局常委 on 15/10/22.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int ret = nums[0], sum = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            if (sum < 0) {
                sum = 0;
            }
            sum += nums[i];
            if (sum > ret) {
                ret = sum;
            }
        }
        return ret;
    }
};
#endif /* solution_h */
