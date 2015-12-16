//
//  main.cpp
//  Remove_Duplicates_from_Sorted_Array
//
//  Created by 中央政治局常委 on 15/12/14.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int shift = 0;
        for (int i = 1; i < nums.size(); ++ i) {
            if (nums[i] == nums[i - 1]) {
                shift ++;
            } else {
                nums[i - shift] = nums[i];
            }
        }
        return nums.size() - shift;
    }
};


int main(int argc, const char * argv[]) {
    Solution test;
    vector<int> nums({1,1,1,3});
    test.removeDuplicates(nums);
    return 0;
}
