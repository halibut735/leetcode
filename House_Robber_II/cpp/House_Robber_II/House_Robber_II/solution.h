//
//  solution.h
//  House_Robber_II
//
//  Created by 中央政治局常委 on 15/10/31.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 3) return nums.empty() ? 0 : 1 == nums.size() || nums[1] <= nums[0] ? nums[0] : nums[1];
        
        vector<int> nums1(nums.begin() + 1, nums.end());
        vector<int> nums2(nums.begin() + 2, nums.end());
        nums2.push_back(nums[0]);
        long len = nums1.size();
        
        for (int i = 1; i < len; ++ i) {
            nums1[i] = max(nums1[i - 1], nums1[i] + (i == 1 ? 0 : nums1[i - 2]));
            nums2[i] = max(nums2[i - 1], nums2[i] + (i == 1 ? 0 : nums2[i - 2]));
        }
        return max(nums1[len - 1], nums2[len - 1]);
    }
};
#endif /* solution_h */
