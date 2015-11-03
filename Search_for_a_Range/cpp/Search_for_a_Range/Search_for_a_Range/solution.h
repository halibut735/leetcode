//
//  solution.h
//  Search_for_a_Range
//
//  Created by 中央政治局常委 on 15/10/31.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int start = 0, end = nums.size(), lret = -1, rret = -1, middle = 0;
        
        while (start < end) {
            middle = (start + end) / 2;
            if (nums[middle] == target && (!middle || nums[middle - 1] < target)) {
                lret = middle;
                break;
            }
            else if (nums[middle] > target || (nums[middle] == target && nums[middle - 1] == target))
                end = middle;
            else if (nums[middle] < target)
                start = middle + 1;
        }
        if (-1 == lret) return {-1, -1};
        
        
        start = lret;
        end = nums.size();
        
        while (start < end) {
            middle = (start + end) / 2;
            if (nums[middle] == target && (nums.size() == middle + 1 || nums[middle + 1] > target)){
                rret =  middle;
                break;
            }
            else if (nums[middle] < target || (nums[middle + 1] == target && nums[middle] == target))
                start = middle + 1;
            else if (nums[middle] > target)
                end = middle;
        }
        return {lret, rret};
    }
};
#endif /* solution_h */
