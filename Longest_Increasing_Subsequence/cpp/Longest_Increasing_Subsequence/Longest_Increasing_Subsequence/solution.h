//
//  solution.h
//  Longest_Increasing_Subsequence
//
//  Created by 中央政治局常委 on 15/11/20.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        long nlen = nums.size();
        vector<int> len;
        for (int i = 1; i < nlen; ++ i) {
            int index = findIndex(len, nums[i]);
            if (len[index] == nums[i]) continue;
            if (index < 1) len[0] = min(nums[i], len[0]);
        }
        return len.size();
    }
private:
    int findIndex(vector<int> &len, int val) {
        int ll = 0, rr = len.size(), middle = -1;
        while (ll < rr) {
            middle = (ll + rr) / 2;
            if (len[middle] == val)
                return -1;
            else if (len[middle] < val)
                ll = middle + 1;
            else
                rr = middle;
        }
        return middle;
    }
};
#endif /* solution_h */
