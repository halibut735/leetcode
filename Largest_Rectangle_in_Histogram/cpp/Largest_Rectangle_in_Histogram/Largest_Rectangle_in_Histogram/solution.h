//
//  solution.h
//  Largest_Rectangle_in_Histogram
//
//  Created by 中央政治局常委 on 15/12/6.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

//跟窗口最小值一样，这里也是去局部区域最小值作比较！想法很好哎。。。棒棒棒哒



class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        height.push_back(0);
        int size_h = height.size(), ret = 0;
        stack<int> stk;
        for (int i = 0; i < size_h; ++ i) {
            while (!stk.empty() && height[stk.top()] >  height[i]) {
                int pos = stk.top();
                stk.pop();
                ret = max(ret, height[pos] * (stk.empty() ? i : i - stk.top() - 1));
            }
            stk.push(i);
        }
        return ret;
    }
};

#endif /* solution_h */
