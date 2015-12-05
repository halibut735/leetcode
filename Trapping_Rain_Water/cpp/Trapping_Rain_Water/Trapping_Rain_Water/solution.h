//
//  solution.h
//  Trapping_Rain_Water
//
//  Created by 中央政治局常委 on 15/11/30.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size(), last = 0, ret = 0;
        vector<int> water(len, 0);
        for (long i = 0; i < height.size(); ++ i) {
            last = height[i] > last ? height[i] : last;
            water[i] = last - height[i];
        }
        last = 0;
        for (long i = len - 1; i >= 0; -- i) {
            last = height[i] > last ? height[i] : last;
            water[i] = min(last - height[i], water[i]);
        }
        for (int each : water) ret += each;
        return ret;
    }
};
#endif /* solution_h */
