//
//  solution.h
//  Single_Number
//
//  Created by 中央政治局常委 on 15/10/22.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto each:nums) {
            ret ^= each;
        }
        return ret;
    }
};
#endif /* solution_h */
