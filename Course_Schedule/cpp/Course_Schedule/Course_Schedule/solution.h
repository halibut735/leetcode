//
//  solution.h
//  Course_Schedule
//
//  Created by 中央政治局常委 on 15/11/18.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> vv(numCourses, {});
        vector<int> indegree(numCourses, 0);
        queue<int> que;
        for (auto each:prerequisites) {
            vv[each.first].push_back(each.second);
            indegree[each.second] ++;
        }
        for (int i = 0; i < numCourses; ++ i) {
            if (!indegree[i]) que.push(i);
        }
        while (!que.empty()) {
            int tmp = que.front();
            que.pop();
            for (auto each:vv[tmp]) {
                indegree[each] --;
                if (!indegree[each])
                    que.push(each);
            }
        }
        for (auto each:indegree) {
            if (each) return false;
        }
        return true;
    }
};
#endif /* solution_h */
