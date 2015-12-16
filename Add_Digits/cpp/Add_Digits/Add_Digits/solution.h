//
//  solution.h
//  Add_Digits
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        return num - 9 * ((num-1) / 9);
    }
};
#endif /* solution_h */
