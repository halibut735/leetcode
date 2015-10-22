//
//  solution.h
//  Expression_Add_Operators
//
//  Created by 中央政治局常委 on 15/10/20.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ret;
        dfs("", num, target, 0, 0, ret);
        return ret;
    }
private:
    void dfs(string curStr, string unProcessedStr, const int target, long long preNum, long long curRes, vector<string>& ret){
        if (unProcessedStr.empty() && curRes == target) {
            ret.push_back(curStr);
            return;
        }
        
        for (int i = 1; i <= unProcessedStr.size(); ++ i) {
            string tmpStr = unProcessedStr.substr(0, i);
            long long tmpNum = stoll(tmpStr);
            string nextStr = unProcessedStr.substr(i);
            if (tmpStr.size() > 1 && tmpStr[0] == '0') {
                return ;
            }
            
            if (curStr.empty()) {
                dfs(tmpStr, nextStr, target, tmpNum, tmpNum, ret);
            }
            else {
                dfs(curStr + "*" + tmpStr, nextStr, target, preNum * tmpNum, curRes - preNum + preNum * tmpNum, ret);
                dfs(curStr + "+" + tmpStr, nextStr, target, tmpNum, curRes + tmpNum, ret);
                dfs(curStr + "-" + tmpStr, nextStr, target, -1 * tmpNum, curRes - tmpNum, ret);
            }
        }
    }
};
#endif /* solution_h */
