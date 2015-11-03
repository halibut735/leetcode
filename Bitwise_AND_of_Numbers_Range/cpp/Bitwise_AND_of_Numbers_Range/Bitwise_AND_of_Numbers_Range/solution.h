//
//  solution.h
//  Bitwise_AND_of_Numbers_Range
//
//  Created by 中央政治局常委 on 15/11/1.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int ret = 0;
        bool flag = false;
        for (int i = 30; i >= 0; -- i) {
            int topBit = 1 << i;
            if (topBit & m || topBit & n)
                flag = true;
            if (flag && ((topBit & m) == (topBit & n))) {
                ret |= topBit & m;
            }
            else if (flag)
                break;
        }
        return ret;
    }
};
#endif /* solution_h */
