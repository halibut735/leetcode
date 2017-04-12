//
//  main.cpp
//  Move_Zeroes
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        unsigned long ll = 0, rr = 0;
        while (rr < nums.size()) {
            while (rr < nums.size() && !nums[rr ++]);
            nums[ll ++] = nums[rr - 1];
        }
        while (ll < nums.size()) nums[ll ++] = 0;
    }
};


int main(int argc, const char * argv[]) {
    vector<int> nums({0});
    Solution sol;
    sol.moveZeroes(nums);
    cout << nums[0] << endl;
    return 0;
}
