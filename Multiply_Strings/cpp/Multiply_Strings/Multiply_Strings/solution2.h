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
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ret("0"), localsum;
        if (num1 == "0" || num2 == "0") return "0";
        for (int i = 0; i < num2.size(); ++ i) {
            localsum = revsch(num1, num2[i], i);
            ret = revadd(ret, localsum);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
private:
    string revadd(string a, string b) {
        int carry = 0;
        string ret;
        for (int i = 0; i < a.size() || i < b.size(); ++ i) {
            int localsum = (i < a.size() ? a[i] - '0' : 0) + (i < b.size() ? b[i] - '0' : 0) + carry;
            carry = localsum / 10;
            localsum %= 10;
            ret.push_back('0' + localsum);
        }
        if(carry) ret.push_back('1');
        return ret;
    }
    string revsch(string reva, char b, int zerocnt) {
        int carry = 0;
        string ret(zerocnt, '0');
        for (int i = 0; i < reva.size(); ++ i) {
            int tmp = (b - '0') * (reva[i] - '0') + carry;
            carry = tmp / 10;
            tmp %= 10;
            ret.push_back('0' + tmp);
        }
        if (carry) ret.push_back('0' + carry);
        return ret;
    }
};











#endif /* solution_h */
