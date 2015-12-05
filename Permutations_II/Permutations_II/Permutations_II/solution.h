//
//  solution.h
//  Permutations_II
//
//  Created by 中央政治局常委 on 15/11/26.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.empty()) return ret;
        sort(nums.begin(), nums.end());
        ret.push_back(nums);
        bool isBiggest = nums.size() == 1;
        while (!isBiggest) {
            isBiggest = true;
            for (long i = nums.size() - 1; i > 0; -- i) {
                if (nums[i - 1] < nums[i]) {
                    isBiggest = false;
                    for (long j = nums.size() - 1; j > i - 1; -- j) {
                        if (nums[j] > nums[i - 1]) {
                            swap(nums[j], nums[i - 1]);
                            reverse(nums.begin() + i, nums.end());
                            break;
                        }
                    }
                    ret.push_back(nums);
                    break;
                }
            }
        }
        return ret;
    }
private:
    void swap(int &x, int &y) {
        int tmp = x;
        x = y;
        y = tmp;
    }
};
#endif /* solution_h */
