//
//  solution.h
//  Valid_Number
//
//  Created by 中央政治局常委 on 15/9/23.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        cnt_dot = cnt_e = start = 0;
        end = s.size() -1;
        while (1) {
            if (s[start] == ' ' && start != s.size()) {
                start ++;
            }
            else
                break;
        }
        if (start == s.size()) {
            return false;
        }
        while (1) {
            if (s[end] == ' ') {
                end --;
            }
            else
                break;
        }
        if (s[start] == '-' || s[start] == '+') {
            start ++;
        }
        for (int i = start; i <= end; ++i) {
            switch (s[i]) {
                case '-':
                    return false;
                    break;
                    
                case '+':
                    return false;
                    break;
                
                case '.':
                    cnt_dot ++;
                    if (cnt_dot > 1) {
                        return false;
                    }
                    if (start == end) {
                        return false;
                    }
                    if (i+1 <= end && (!is_digital(s[i+1]) || s[i+1] != 'e') ) {
                        return false;
                    }
                    if (i-1 >= start && !is_digital(s[i-1])) {
                        return false;
                    }
                    break;
                    
                case 'e':
                    cnt_e ++;
                    cnt_dot == 1 ? cnt_dot -- : cnt_dot;
                    if (cnt_e > 1) {
                        return false;
                    }
                    if (i == start || i == end) {
                        return false;
                    }
                    if (i-1 >= start && !is_digital(s[i-1])) {
                        return false;
                    }
                    
                    if (i+1 <= end && (!is_digital(s[i+1]) || s[i-1] == '.')) {
                        return false;
                    }
                    break;
                    
                default:
                    if (!is_digital(s[i])) {
                        return false;
                    }
                    break;
            }
        }
        return true;
    }
private:
    int cnt_dot, cnt_e;
    int start, end;
    bool is_digital(const char &c){
        if (c <= '9' && c >= '0')
            return true;
        else
            return false;
    }
};


#endif /* solution_h */
