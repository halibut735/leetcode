//
//  solution.h
//  Sliding_Window_Maximum
//
//  Created by 中央政治局常委 on 15/12/5.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if (nums.empty()) return ret;
        multiset<int, greater<int>> priorityque;
        for (int i = 0; i < k - 1; ++ i) priorityque.insert(nums[i]);
        for (int i = k - 1; i < nums.size(); ++ i) {
            priorityque.insert(nums[i]);
            ret.push_back(*priorityque.begin());
            priorityque.erase(priorityque.find(nums[i - k + 1]));
        }
        return ret;
    }
};
#endif /* solution_h */
