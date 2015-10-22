//
//  solution.h
//  Basic_Calculator
//
//  Created by 中央政治局常委 on 15/10/15.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> opt;
        int numsToPush;
        for (int i = 0; i < s.size(); ++ i) {
            switch (s[i]) {
                case ' ':
                    break;
                    
                case ')':
                    opt.pop();
                    if (!opt.empty() && (opt.top() == '-' || opt.top() == '+')) {
                        int tmp1 = nums.top();
                        nums.pop();
                        int tmp2 = nums.top();
                        nums.pop();
                        int tmp3 = opt.top() == '-' ? tmp2 - tmp1 : tmp1 + tmp2;
                        nums.push(tmp3);
                        opt.pop();
                    }
                    break;
                    
                case '(':
                    opt.push('(');
                    break;
                    
                case '+':
                    opt.push('+');
                    break;
                    
                case '-':
                    opt.push('-');
                    break;
                    
                default:
                    numsToPush = 0;
                    while (i < s.size() && s[i] <= '9' && s[i] >= '0') {
                        numsToPush = 10 * numsToPush + s[i] - '0';
                        i ++;
                    }
                    i --;
                    if (!opt.empty() && (opt.top() == '-' || opt.top() == '+')) {
                        numsToPush = opt.top() == '-' ? nums.top() - numsToPush : nums.top() + numsToPush;
                        nums.pop();
                        opt.pop();
                    }
                    nums.push(numsToPush);
                    break;
            }
        }
        return nums.top();
    }
};
#endif /* solution_h */
