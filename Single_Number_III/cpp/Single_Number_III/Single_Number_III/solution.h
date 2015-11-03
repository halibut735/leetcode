//
//  solution.h
//  Single_Number_III
//
//  Created by 中央政治局常委 on 15/10/22.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int tmp = 0;
        vector<int> ret;
        vector<int> vec1, vec2;
        for (auto each:nums) tmp ^= each;
        int lastOneVal = tmp - ((tmp - 1) & tmp);
        
        for (auto each:nums) {
            if (lastOneVal & each)
                vec1.push_back(each);
            else
                vec2.push_back(each);
        }
        
        tmp = 0;
        for (auto each:vec1)  tmp ^= each;
        ret.push_back(tmp);
        tmp = 0;
        for (auto each:vec2)  tmp ^= each;
        ret.push_back(tmp);
        return ret;
    }
};
#endif /* solution_h */
