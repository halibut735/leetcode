//
//  solution.h
//  Longest_Valid_Parentheses
//
//  Created by 中央政治局常委 on 15/9/16.
//  Copyright (c) 2015年 中央政治局常委. All rights reserved.
//

#ifndef Longest_Valid_Parentheses_solution_h
#define Longest_Valid_Parentheses_solution_h
#include <string>
#include <stack>
using namespace std;


class Solution {
public:
    Solution():ret(0), tmp(0){}
    int longestValidParentheses(string s) {
        ret = tmp = 0;
        stack<int> match;
        for (string::iterator it = s.begin(); it != s.end(); ++it) {
            switch (*it) {
                case '(':
                    match.push(tmp);
                    tmp = 0;
                    break;
                    
                case ')':
                    if (match.empty()) {
                        tmp = 0;
                        continue;
                    }
                    tmp += 2 + match.top();
                    match.pop();
                    ret = tmp>ret? tmp:ret;
                    break;
                    
                default:
                    break;
            }
        }
        return ret;
    }
private:
    int ret, tmp;
};

#endif
