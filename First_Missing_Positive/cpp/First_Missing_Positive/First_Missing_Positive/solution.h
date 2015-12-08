//
//  solution.h
//  First_Missing_Positive
//
//  Created by 中央政治局常委 on 15/12/7.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++ i) {
            while (nums[i] <= nums.size() && nums[i] > 0 && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < nums.size(); ++ i) {
            if (i + 1 != nums[i])
                return i + 1;
        }
        return nums.size() + 1;
    }
};
#endif /* solution_h */
