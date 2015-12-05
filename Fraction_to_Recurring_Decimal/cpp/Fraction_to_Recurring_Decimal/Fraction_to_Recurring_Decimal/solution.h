//
//  solution.h
//  Fraction_to_Recurring_Decimal
//
//  Created by 中央政治局常委 on 15/11/16.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <fstream>
using namespace std;


class Solution {
public:
    string fractionToDecimal(int a, int b) {
        unordered_map<long long, long long> reflect;
        long long numerator = a, denominator = b;
        long pos;
        string ret = (numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0) ? "-" : "";
        numerator = abs(numerator);
        denominator = abs(denominator);
        ret += to_string(numerator / denominator);
        numerator = numerator % denominator;
        ret += ret.empty() ? "0." : ".";
        pos = ret.size();
        while (numerator) {
            if (reflect.count(numerator)) {
                ret.push_back(')');
                ret.insert(reflect.find(numerator)->second, "(");
                break;
            }
            reflect[numerator] = pos ++;
            ret += to_string(numerator * 10 / denominator);
            numerator = numerator * 10 % denominator;
        }
        if (ret[ret.size() - 1] == '.') ret.pop_back();
        return ret;
    }
};
#endif /* solution_h */
