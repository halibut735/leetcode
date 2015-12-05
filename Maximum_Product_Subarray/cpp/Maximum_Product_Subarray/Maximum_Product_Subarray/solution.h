//
//  solution.h
//  Maximum_Product_Subarray
//
//  Created by 中央政治局常委 on 15/11/18.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ret = nums[0], pre = 1, next = 1;
        bool flag = false;
        for (int i = 0; i < nums.size(); ++ i) {
            if (nums[i] == 0) {
                ret = max(nums[i], ret);
                pre = next = 1;
                flag = false;
            }
            else {
                pre *= nums[i];
                if (flag) next *= nums[i];
                ret = max(ret, pre);
                if (flag) ret = max(ret, next);
                if (nums[i] < 0)
                    flag = true;
            }
        }
        return ret;
    }
};
#endif /* solution_h */
