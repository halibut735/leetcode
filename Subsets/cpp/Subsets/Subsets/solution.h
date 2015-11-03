//
//  solution.h
//  Subsets
//
//  Created by 中央政治局常委 on 15/10/28.
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
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        ret.push_back({});
        for (int i = 1; i <= nums.size(); ++ i) {
            auto tmp = generateSub(nums, i, nums.size() - 1);
            for (auto each:tmp)
                ret.push_back(each);
        }
        return ret;
    }
private:
    vector<vector<int>> generateSub(vector<int>& nums, int n, int tail){
        vector<vector<int>> local;
        vector<int> tmp;
        if (!n || tail + 1 < n) return local;
        if (n == 1) {
            for (int i = tail; i >= 0; -- i)
                local.push_back({nums[i]});
            return local;
        }
        for (int i = tail; i >= 0; -- i) {
            auto tmp = generateSub(nums, n - 1, i - 1);
            for (auto each:tmp) {
                each.push_back(nums[i]);
                local.push_back(each);
            }
        }
        return local;
    }
};
#endif /* solution_h */
