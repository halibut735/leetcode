//
//  solution.h
//  Remove_Invalid_Parentheses
//
//  Created by 中央政治局常委 on 15/12/7.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;




class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int leftremove = 0, rightremove = 0;
        unordered_set<string> res;
        for (char c : s) {
            if (c == ')' && leftremove) leftremove --;
            else if (c == ')') rightremove ++;
            else if (c == '(') leftremove ++;
        }
        dfs(res, leftremove, rightremove, s, 0, 0);
        if (res.empty()) return {""};
        return vector<string>(res.begin(), res.end());
    }
private:
    void dfs(unordered_set<string> &res, int leftremove, int rightremove, string s, int index, int notclosed) {
        int i = index;
        for (i = index; i < s.size(); ++ i) {
            switch (s[i]) {
                case '(':
                    if (leftremove) 
                        dfs(res, leftremove - 1, rightremove, s.substr(0, i) + s.substr(i + 1), i, notclosed);
                    notclosed ++;
                    break;
                    
                case ')':
                    if (rightremove)
                        dfs(res, leftremove, rightremove - 1, s.substr(0, i) + s.substr(i + 1), i, notclosed);
                    notclosed --;
                    break;
                    
                default:
                    break;
            }
            if (notclosed < 0) break;
        }
        if (!notclosed && leftremove == rightremove && i == s.size())
            res.insert(s);
    }
};



#endif /* solution_h */
