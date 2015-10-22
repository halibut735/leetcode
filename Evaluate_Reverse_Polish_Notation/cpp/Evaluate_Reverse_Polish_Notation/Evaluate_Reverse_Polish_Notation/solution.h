//
//  solution.h
//  Evaluate_Reverse_Polish_Notation
//
//  Created by 中央政治局常委 on 15/10/15.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <vector>
#include <string>
#include <stack>

using namespace std;



class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int opt1, opt2;
        stack<int> stk;
        for (auto &each:tokens) {
            if (each == "*") {
                opt1 = stk.top();
                stk.pop();
                opt2 = stk.top();
                stk.pop();
                stk.push(opt2 * opt1);
            }
            else if (each == "+") {
                opt1 = stk.top();
                stk.pop();
                opt2 = stk.top();
                stk.pop();
                stk.push(opt1 + opt2);
            }
            else if (each == "/") {
                opt1 = stk.top();
                stk.pop();
                opt2 = stk.top();
                stk.pop();
                stk.push(opt2 / opt1);
            }
            else if (each == "-") {
                opt1 = stk.top();
                stk.pop();
                opt2 = stk.top();
                stk.pop();
                stk.push(opt2 - opt1);
            }
            else{
                stk.push(strToInt(each));
            }
        }
        return stk.top();
    }
private:
    int strToInt(string &str){
        int ret = 0;
        bool isNegative = false;
        for (auto &each:str) {
            if (each == '+' || each == '-') {
                isNegative = each == '-' ? true : false;
                continue;
            }
            ret *= 10;
            ret += each - '0';
        }
        ret = isNegative ? -1 * ret : ret;
        return ret;
    }
};
#endif /* solution_h */
