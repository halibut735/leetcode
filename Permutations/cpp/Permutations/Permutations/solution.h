//
//  solution.h
//  Permutations
//
//  Created by 中央政治局常委 on 15/10/25.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret, tmp;
        vector<int> middle;
        if (nums.empty()) return ret;
        if (nums.size() == 1) {
            ret.push_back({nums[0]});
            return ret;
        }
        for (auto it = nums.begin(); it != nums.end(); ++ it) {
            vector<int> input(nums.begin(), it);
            input.insert(input.end(), it + 1, nums.end());
            tmp = permute(input);
            for (auto each:tmp) {
                middle.assign(1, *it);
                middle.insert(middle.end(), each.begin(), each.end());
                ret.push_back(middle);
            }
        }
        return ret;
    }
};
#endif /* solution_h */
