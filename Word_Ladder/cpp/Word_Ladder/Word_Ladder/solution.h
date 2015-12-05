//
//  solution.h
//  Word_Ladder
//
//  Created by 中央政治局常委 on 15/11/17.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_set<string> isVisited;
        int ret = 0;
        queue<string> que;
        isVisited.insert(beginWord);
        que.push(beginWord);
        que.push("");
        ret ++;
        while (!que.empty()) {
            string tmp = que.front();
            que.pop();
            if (tmp.empty() && !que.empty()) {
                que.push("");
                ret ++;
            }
            else {
                for (int i = 0; i < tmp.size(); ++ i) {
                    string next = tmp;
                    for (int j = 0; j < 26; ++ j) {
                        next[i] = 'a' + j;
                        if (next == endWord)
                            return ret + 1;
                        if (wordList.count(next) && !isVisited.count(next) && next != tmp){
                            isVisited.insert(next);
                            que.push(next);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
#endif /* solution_h */













