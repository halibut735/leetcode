//
//  solution.h
//  Basic_Calculator_II
//
//  Created by 中央政治局常委 on 15/10/15.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <string>
#include <stack>
#include <queue>
using namespace std;



class Solution {
public:
    int calculate(string s) {
        deque<int> stk;
        int tmp;
        for (int i = 0; i < s.size(); ++ i) {
            switch (s[i]) {
                case ' ':
                    break;
                    
                case '+':
                    stk.push_back(-1);
                    break;
                    
                case '-':
                    stk.push_back(-2);
                    break;
                    
                case '*':
                    stk.push_back(-3);
                    break;
                    
                case '/':
                    stk.push_back(-4);
                    break;
                    
                default:
                    tmp = 0;
                    while (i < s.size() && s[i] <= '9' && s[i] >= '0') {
                        tmp = tmp * 10 + s[i] - '0';
                        ++ i;
                    }
                    -- i;
                    if (!stk.empty() && stk.back() == -3) {
                        stk.pop_back();
                        tmp = stk.back() * tmp;
                        stk.pop_back();
                    }
                    if (!stk.empty() && stk.back() == -4) {
                        stk.pop_back();
                        tmp = stk.back() / tmp;
                        stk.pop_back();
                    }
                    stk.push_back(tmp);
                    break;
            }
        }
        
        
        while (stk.size() >= 2) {
            tmp = stk.front();
            stk.pop_front();
            if (stk.front() == -1) {
                stk.pop_front();
                tmp = stk.front() + tmp;
            }
            if (stk.front() == -2) {
                stk.pop_front();
                tmp = tmp - stk.front();
            }
            stk.pop_front();
            stk.push_front(tmp);
        }
        return stk.front();
    }
};

#endif /* solution_h */
