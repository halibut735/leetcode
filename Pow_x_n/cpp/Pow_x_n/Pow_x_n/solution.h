//
//  solution.h
//  Pow_x_n
//
//  Created by 中央政治局常委 on 15/11/1.
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
    double myPow(double x, int n) {
        if (n == 0) return 1;
        int multipy = n % 2;
        double tmp = myPow(x, n/2);
        return tmp * tmp * (!multipy ? 1 : multipy == 1 ? x : 1 / x);
    }
};
#endif /* solution_h */
