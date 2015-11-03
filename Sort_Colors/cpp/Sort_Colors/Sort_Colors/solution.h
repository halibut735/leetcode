//
//  solution.h
//  Sort_Colors
//
//  Created by 中央政治局常委 on 15/10/25.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, white = 0, blue = 0;
        for (auto each:nums) {
            switch (each) {
                case 0:
                    red ++;
                    break;
                    
                case 1:
                    white ++;
                    break;
                    
                default:
                    blue ++;
                    break;
            }
        }
        nums.clear();
        nums.insert(nums.end(), red, 0);
        nums.insert(nums.end(), white, 1);
        nums.insert(nums.end(), blue, 2);
    }
};
#endif /* solution_h */
