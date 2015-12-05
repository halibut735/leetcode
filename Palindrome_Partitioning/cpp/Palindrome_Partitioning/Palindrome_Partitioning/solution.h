//
//  solution.h
//  Palindrome_Partitioning
//
//  Created by 中央政治局常委 on 15/11/25.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> path;
        dfs(ret, path, s);
        return ret;
    }
    
private:
    void dfs(vector<vector<string>> &ret, vector<string> path, string s) {
        if (s.empty()) {
            if (!path.empty()) ret.push_back(path);
            return;
        }
        
        for (int i = 0; i < s.size(); ++ i) {
            int head = 0, tail = i;
            while (head <= tail && s[head] == s[tail]) {
                head ++;
                tail --;
            }
            if (head > tail) {
                path.push_back(s.substr(0, i + 1));
                dfs(ret, path, s.substr(i + 1));
                path.pop_back();
            }
        }
    }
};
#endif /* solution_h */
