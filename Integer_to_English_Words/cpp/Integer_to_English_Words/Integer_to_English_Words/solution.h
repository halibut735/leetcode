//
//  solution.h
//  Integer_to_English_Words
//
//  Created by 中央政治局常委 on 15/11/16.
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
    string numberToWords(int num) {
        string ret, eachSection;
        for (int i = 0; i < 4; ++ i) {
            int tmp = num / divisor[i];
            eachSection = three(tmp);
            ret += eachSection.empty() ? "" : eachSection + bigger[i];
            num %= divisor[i];
            if (num && !eachSection.empty()) ret += " ";
        }
        if (ret.empty()) ret = "Zero";
        return ret;
    }
    string three(int num) {
        string ret;
        int tmp = num / 100;
        if (tmp) ret += units[tmp] + " Hundred";
        num %= 100;
        if (!ret.empty() && num) ret += " ";
        if (num < 20) {
            ret += units[num];
        }
        else {
            tmp = num / 10;
            if (tmp) ret += tens[tmp];
            if (tmp && num %10) ret += " ";
            ret += units[num % 10];
        }
        return ret;
    }
private:
    const string units[21] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const string tens[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    const string bigger[4] = {" Billion", " Million", " Thousand", ""};
    int divisor[4] = {1000000000, 1000000, 1000, 1};
};
#endif /* solution_h */
