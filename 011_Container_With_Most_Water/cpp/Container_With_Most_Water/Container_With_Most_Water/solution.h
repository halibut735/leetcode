//
//  solution.h
//  Container_With_Most_Water
//
//  Created by 中央政治局常委 on 15/10/4.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <set>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int level = min(height[left], height[right]);
        int area = (right - left) * level;
        while (1) {
            if (height[left] > height[right])
                right --;
            else
                left ++;
            if (left >= right) break;
            int tmpLow = min(height[left], height[right]);
            if (tmpLow <= level) continue;
            int tmpArea = (right - left) * tmpLow;
            if (tmpArea <= area) continue;
            area = tmpArea;
            level = tmpLow;
        }
        return area;
    }
};
#endif /* solution_h */
