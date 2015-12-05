//
//  solution.h
//  Divide_Two_Integers
//
//  Created by 中央政治局常委 on 15/11/16.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int divide(long long dividend, long long divisor) {
        if (dividend == -2147483648 && divisor == -1) return INT_MAX;
        long long ret = 0, tmp = divisor, cnt = 1;
        bool flag = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
        dividend = abs(dividend);
        divisor = abs(divisor);
        tmp = divisor;
        while (dividend - tmp >= 0) {
            dividend -= tmp;
            ret += cnt;
            tmp += tmp;
            cnt += cnt;
        }
        if (dividend >= divisor) {
            ret += divide(dividend, divisor);
        }
        return flag ? -1 * ret : ret;
    }
};
#endif /* solution_h */
