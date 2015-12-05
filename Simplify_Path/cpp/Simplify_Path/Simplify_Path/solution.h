//
//  solution.h
//  Simplify_Path
//
//  Created by 中央政治局常委 on 15/11/18.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <fstream>
#include <set>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string ret, tmp;
        stack<string> stk1, stk2;
        int uplevel = 0;
        if (path.size() < 2) return path;
        ret = path[0] == '/' ? "/" : "";
        for (auto each:path) {
            if (each == '/') {
                if (!tmp.empty()) stk1.push(tmp);
                tmp.clear();
            }
            else
                tmp.append(1, each);
        }
        if (!tmp.empty()) stk1.push(tmp);
        
        while (!stk1.empty()) {
            tmp = stk1.top();
            stk1.pop();
            if (tmp == ".")
                continue;
            else if (tmp == "..")
                uplevel ++;
            else {
                if (uplevel)
                    uplevel --;
                else
                    stk2.push(tmp);
            }
        }
        
        while (!stk2.empty()) {
            ret += stk2.top();
            ret += "/";
            stk2.pop();
        }
        if (ret[ret.size() - 1] == '/' && ret.size() != 1) ret.pop_back();
        return ret;
    }
};
#endif /* solution_h */
