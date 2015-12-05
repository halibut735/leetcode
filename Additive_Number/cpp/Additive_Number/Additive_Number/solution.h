//
//  solution.h
//  Additive_Number
//
//  Created by 中央政治局常委 on 15/11/29.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i < num.size(); ++ i) {
            for (int j = i + 1; j <= num.size(); ++ j) {
                if (judge(num, 0, i, i, j)) return true;
            }
        }
        return false;
    }
private:
    string add(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ret;
        int carry = 0, cur = 0;
        for (int i = 0; i < a.size() || i < b.size(); ++ i) {
            cur = (i < a.size() ? a[i] : '0') + (i < b.size() ? b[i] : '0') - '0' - '0' + carry;
            carry = cur / 10;
            cur %= 10;
            ret.push_back('0' + cur);
        }
        if (carry) ret.push_back('1');
        reverse(ret.begin(), ret.end());
        return ret;
    }
    bool judge(const string &a, int fx, int fy, int sx, int sy) {
        if ((a[fx] == '0' && fy - fx > 1) || (a[sx] == '0' && sy - sx > 1)) return false;
        string res = add(a.substr(fx, fy - fx), a.substr(sx, sy - sx));
        int len = res.size();
        if (a.substr(sy, len) != res) return false;
        else if (sy + len == a.size()) return true;
        return judge(a, sx, sy, sy, sy + len);
    }
};
#endif /* solution_h */
