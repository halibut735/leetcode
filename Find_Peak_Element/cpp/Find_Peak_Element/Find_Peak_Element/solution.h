//
//  solution.h
//  Find_Peak_Element
//
//  Created by 中央政治局常委 on 15/10/26.
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
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() -1, middle = 0;
        while (left != right) {
            middle = (left + right) / 2;
            if (left == right)
                return left;
            if (nums[middle] < nums[middle + 1])
                left = middle + 1;
            else
                right = middle;
        }
        return left;
    }
};
#endif /* solution_h */
