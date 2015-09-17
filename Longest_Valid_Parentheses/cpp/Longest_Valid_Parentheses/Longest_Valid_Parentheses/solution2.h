//
//  solution2.h
//  Longest_Valid_Parentheses
//
//  Created by 中央政治局常委 on 15/9/16.
//  Copyright (c) 2015年 中央政治局常委. All rights reserved.
//

#ifndef Longest_Valid_Parentheses_solution2_h
#define Longest_Valid_Parentheses_solution2_h


#include <string>
#include <stack>
#include <vector>
using namespace std;


class Solution {
public:
    Solution():ret(0){}
    int longestValidParentheses(const string &str) {
        vector<int> dp(str.size());
        ret = 0;
        for (int i = 1; i < str.size(); ++ i) {
            switch (str[i]) {
                case '(':
                    break;
                    
                case ')':
                    if (i - dp[i-1] -1 >= 0 && str[i - dp[i-1] -1] == '(') {
                        dp[i] = dp[i-1] + 2;
                        if (i - dp[i-1] -2 >= 0) {
                            dp[i] += dp[i - dp[i-1] -2] > 0? dp[i - dp[i-1] -2]:0;
                        }
                        ret = dp[i] > ret? dp[i]:ret;
                    }
                    break;
                    
                default:
                    break;
            }
        }
        return ret;
    }
private:
    int ret;
};


#endif
