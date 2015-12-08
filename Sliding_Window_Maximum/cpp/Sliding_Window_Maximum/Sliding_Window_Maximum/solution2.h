//
//  solution2.h
//  Sliding_Window_Maximum
//
//  Created by 中央政治局常委 on 15/12/5.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution2_h
#define solution2_h
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <vector>
#include <stack>
using namespace std;




class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> deq;
        if (nums.empty()) return ret;
        for (int i = 0; i < k - 1; ++ i) {
            while (!deq.empty() && deq.back() < nums[i])
                deq.pop_back();
            deq.push_back(nums[i]);
        }
        for (int i = k - 1; i < nums.size(); ++ i) {
            while (!deq.empty() && deq.back() < nums[i])
                deq.pop_back();
            deq.push_back(nums[i]);
            ret.push_back(deq.front());
            if (nums[i - k + 1] == deq.front())
                deq.pop_front();
        }
        return ret;
    }
};



#endif /* solution2_h */
