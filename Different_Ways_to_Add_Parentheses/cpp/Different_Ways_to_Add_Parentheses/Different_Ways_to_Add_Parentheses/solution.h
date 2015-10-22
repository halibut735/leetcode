//
//  solution.h
//  Different_Ways_to_Add_Parentheses
//
//  Created by 中央政治局常委 on 15/10/15.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;
        for (int i = 0; i < input.size(); ++ i) {
            if (isOperator(input[i])) {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (auto eachx:left) {
                    for (auto eachy:right) {
                        ret.push_back(cal(eachx, eachy, input[i]));
                    }
                }
            }
        }
        if (ret.empty()) {
            ret.push_back(stoi(input));
        }
        return ret;
    }
private:
    inline bool isOperator(char chr){
        return chr == '+' || chr == '-' || chr == '*';
    }
    inline int cal(int a, int b, char op){
        switch (op) {
            case '+':
                return a + b;
                break;
            case '-':
                return a - b;
                break;
            default:
                return a * b;
                break;
        }
    }
};
#endif /* solution_h */
