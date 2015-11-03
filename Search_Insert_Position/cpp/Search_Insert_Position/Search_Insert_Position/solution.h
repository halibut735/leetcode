//
//  solution.h
//  Search_Insert_Position
//
//  Created by 中央政治局常委 on 15/10/22.
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
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, int(nums.size()));
    }
    
private:
    int binarySearch(vector<int>& nums, int target, int start, int end){
        int middle = (start + end) / 2;
        if (end == start || nums[middle] == target) {
            return middle;
        }
        else if (nums[middle] < target){
            return binarySearch(nums, target, middle + 1, end);
        }
        else if (nums[middle] > target){
            return binarySearch(nums, target, start, middle);
        }
        return 0;
    }
};
#endif /* solution_h */
