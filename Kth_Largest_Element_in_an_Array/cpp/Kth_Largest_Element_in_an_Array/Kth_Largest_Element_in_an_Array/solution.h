//
//  solution.h
//  Kth_Largest_Element_in_an_Array
//
//  Created by 中央政治局常委 on 15/10/28.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int maginL = 0, maginR = nums.size() - 1;
        while (maginL < maginR) {
            int left = maginL, right = maginR;
            int key  = nums[left];
            while (left < right) {
                while (left < right && nums[right] <= key) -- right;
                nums[left] = nums[right];
                while (left < right && nums[left] >= key) ++ left;
                nums[right] = nums[left];
            }
            nums[left] = key;
            if (left + 1 == k) return nums[left];
            else if (left + 1 < k)
                maginL = left + 1;
            else
                maginR = right - 1;
        }
        return nums[k - 1];
    }
};
#endif /* solution_h */
