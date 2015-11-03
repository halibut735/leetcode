//
//  solution.h
//  Single_Number_II
//
//  Created by 中央政治局常委 on 15/10/22.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> cntBit(32);
        int ret = 0;
        for (auto each:nums) {
            for (int i = 0; i < 32; ++ i) {
                if (each & (1 << i)) {
                    cntBit[i] = (cntBit[i] + 1) % 3;
                }
            }
        }
        for (int i = 0; i < 32; ++ i) {
            if (cntBit[i]) {
                ret |= 1 << i;
            }
        }
        return ret;
    }
};
#endif /* solution_h */
