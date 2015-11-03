//
//  solution.h
//  Jump_Game
//
//  Created by 中央政治局常委 on 15/11/1.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        for (long i = nums.size() - 1; i >= 0; -- i) {
            long farReach = min(long(nums.size() - 1), i + nums[i]);
            nums[i] = farReach;
            for (long j = i + 1; i <= farReach; ++ j) {
                nums[i] = max(nums[i], nums[j]);
                j = nums[j];
            }
        }
    }
};
#endif /* solution_h */
