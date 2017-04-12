//
//  main.cpp
//  Wiggle_Sort_II
//
//  Created by 中央政治局常委 on 16/1/20.
//  Copyright © 2016年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        bool isgreater = true;
        for (int i = 1; i < nums.size(); ++ i, isgreater = !isgreater) {
            if ((isgreater && nums[i] > nums[i - 1]) ||
                (!isgreater && nums[i] < nums[i - 1]))
                continue;
            if ((isgreater && nums[i] < nums[i - 1]) ||
                (!isgreater && nums[i] > nums[i - 1]))
                swap(nums[i], nums[i - 1]);
        }
        nums = nums;
    }
};



int main(int argc, const char * argv[]) {
    Solution test;
    vector<int> nums({1, 2,3,4,5,6,7,8});
    test.wiggleSort(nums);
    return 0;
}
