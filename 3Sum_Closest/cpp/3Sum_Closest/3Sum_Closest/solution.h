//
//  solution.h
//  3Sum_Closest
//
//  Created by 中央政治局常委 on 15/11/7.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = nums[0] + nums[1] + nums[2], tmp = 0;
        multiset<int> acce;
        multiset<int>::iterator tmpIt;
        for (auto each:nums)
            acce.insert(each);
        
        for (int i = 0; i < nums.size(); ++ i) {
            for (int j = i + 1; j < nums.size(); ++ j) {
                tmp = target - nums[i] - nums[j];
                tmpIt = acce.lower_bound(tmp);
                if (tmpIt != acce.end()) {
                    auto upBound = tmpIt;
                    if (min(nums[i], nums[j]) == * upBound) upBound ++;
                    if (upBound != acce.end() && max(nums[j], nums[i]) == * upBound) upBound ++;
                    if (upBound != acce.end() && *upBound == tmp) return target;
                    if (upBound != acce.end()) ret = abs(tmp - *upBound) < abs(ret - target) ? nums[i] + nums[j] + *upBound : ret;
                }
                if (tmpIt != acce.begin()) {
                    tmpIt --;
                    if (max(nums[j], nums[i]) == * tmpIt) {
                        if (tmpIt != acce.begin()) tmpIt --;
                        else continue;
                    }
                    if (min(nums[i], nums[j]) == * tmpIt) {
                        if (tmpIt != acce.begin()) tmpIt --;
                        else continue;
                    }
                    ret = abs(tmp - *tmpIt) < abs(ret - target) ? nums[i] + nums[j] + *tmpIt : ret;
                }
            }
        }
        return ret;
    }
};
#endif /* solution_h */
