//
//  solution.h
//  Valid_Parentheses
//
//  Created by 中央政治局常委 on 15/12/9.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); ++ i) {
            switch (s[i]) {
                case '(':
                case '[':
                case '{':
                    stk.push(s[i]);
                    break;
                    
                    
                case ')':
                    if (stk.empty() || stk.top() != '(') return false;
                    else stk.pop();
                    break;
                    
                case ']':
                    if (stk.empty() || stk.top() != '[') return false;
                    else stk.pop();
                    break;
                    
                case '}':
                    if (stk.empty() || stk.top() != '{') return false;
                    else stk.pop();
                    break;
                    
                default:
                    break;
            }
        }
        return stk.empty();
    }
};
#endif /* solution_h */
