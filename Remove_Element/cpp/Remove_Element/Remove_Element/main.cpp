//
//  main.cpp
//  Remove_Element
//
//  Created by 中央政治局常委 on 15/12/9.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int shift = 0;
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] == val)  shift ++;
            else nums[i - shift] = nums[i];
        }
        return nums.size() - shift;
    }
};

int main(int argc, const char * argv[]) {
    Solution test;
    vector<int> nums({1,1,1,3,3,3,4});
    test.removeElement(nums, 3);
    return 0;
}
