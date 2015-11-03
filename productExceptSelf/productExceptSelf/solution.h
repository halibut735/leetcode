//
//  solution.h
//  class Solution {  public:      vector<int> productExceptSelf(vector<int>& nums) {                }  Product_of_Array_Except_Self
//
//  Created by 中央政治局常委 on 15/10/22.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ret;
        long long product = 1;
        int cntZero = 0;
        for (auto each:nums) {
            if (!each)
                cntZero ++;
            else
                product *= each;
        }
        if (!cntZero) {
            for (auto each:nums)
                ret.push_back(product / each);
        }
        else if (cntZero == 1){
            for (auto each:nums){
                if (each)
                    ret.push_back(0);
                else
                    ret.push_back(product);
            }
        }
        if (cntZero > 1) {
            ret.insert(ret.begin(), nums.size(), 0);
        }
        return ret;
    }
};
#endif /* solution_h */
