//
//  solution.h
//  Maximum_Gap
//
//  Created by 中央政治局常委 on 15/12/7.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <string>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int len = (int) nums.size(), gap = 0, diff = 0, llower = 0, upup = 0, pre = 0;
        auto tmp = minmax_element(nums.begin(), nums.end());
        llower = *tmp.first;
        upup = *tmp.second;
        if (llower == upup) return 0;
        diff = gap = max((upup - llower) / (len - 1), 1);
        vector<int> bucketmin((upup - llower) / gap + 1, INT_MAX), bucketmax((upup - llower) / gap + 1, INT_MIN);
        for (int i = 0; i < len; ++ i) {
            int pos = (nums[i] - llower) / diff;
            bucketmin[pos] = min(bucketmin[pos], nums[i]);
            bucketmax[pos] = max(bucketmax[pos], nums[i]);
        }
        pre = bucketmax[0];
        for (int i = 1; i < bucketmax.size(); ++ i) {
            if (bucketmax[i] == INT_MIN && bucketmin[i] == INT_MAX) continue;
            gap = max(gap, bucketmin[i] - pre);
            pre = bucketmax[i];
        }
        return gap;
    }
};


#endif /* solution_h */
