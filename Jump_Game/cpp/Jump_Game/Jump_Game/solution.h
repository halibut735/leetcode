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
        int len = nums.size();
        for (int i = len - 1; i >= 0; -- i) {
            int farReach = min(len - 1, i + nums[i]);
            nums[i] = farReach;
            for (int j = i + 1; j <= farReach && j < len; ++ j) {
                nums[i] = max(nums[i], nums[j]);
                j = nums[j];
            }
        }
        return nums[0] == len - 1;
    }
};
#endif /* solution_h */
