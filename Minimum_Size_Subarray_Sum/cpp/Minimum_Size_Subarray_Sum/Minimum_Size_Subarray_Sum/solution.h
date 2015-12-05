//
//  solution.h
//  Minimum_Size_Subarray_Sum
//
//  Created by 中央政治局常委 on 15/11/27.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <set>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, ret = INT_MAX, len = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            sum += nums[i];
            ++ len;
            if (sum >= s) {
                while (sum >= s) {
                    sum -= nums[i + 1 - len];
                    len --;
                }
                ret = min(ret, len + 1);
            }
        }
        ret = ret == INT_MAX ? 0 : ret;
        return ret;
    }
};
#endif /* solution_h */
