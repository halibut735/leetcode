//
//  solution.h
//  Multiply_Strings
//
//  Created by 中央政治局常委 on 15/11/29.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string ret(num1.size() + num2.size(), '0');
        int carry = 0, local = 0, shift = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < num1.size(); ++ i) {
            for (int j = 0; j < num2.size(); ++ j) {
                local = (num1[i] - '0') * (num2[j] - '0') + ret[i + j] - '0';
                carry = local / 10;
                local %= 10;
                ret[i + j] = '0' + local;
                
                shift = 1;
                while (carry) {
                    local = carry + ret[i + j + shift] - '0';
                    carry = local / 10;
                    local %= 10;
                    ret[i + j + shift] = '0' + local;
                    ++ shift;
                }
            }
        }
        reverse(ret.begin(), ret.end());
        shift = 0;
        while (ret[shift ++] == '0') ;
        ret = ret.substr(-- shift);
        return ret.empty() ? "0" : ret;
    }
};











#endif /* solution_h */
