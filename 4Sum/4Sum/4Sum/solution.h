//
//  solution.h
//  4Sum
//
//  Created by 中央政治局常委 on 15/11/19.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <fstream>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        long len = nums.size();
        for (int i = 0; i < len; ++ i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < len; ++ j) {
                int ll = j + 1, rr = len - 1;
                if (j > i + 1 && nums[j - 1] == nums[j]) continue;
                while (ll < rr) {
                    int sum = nums[i] + nums[j] + nums[ll] + nums[rr];
                    if (ll > j + 1 && nums[ll] == nums[ll - 1])
                        ll ++;
                    else if (rr < len - 1 && nums[rr] == nums[rr + 1])
                        rr --;
                    else if (sum == target) {
                        ret.push_back({nums[i], nums[j], nums[ll], nums[rr]});
                        ll ++;
                    } else if (sum < target)
                        ll ++;
                    else
                        rr --;
                }
            }
        }
        return ret;
    }
};
#endif /* solution_h */
