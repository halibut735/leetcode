//
//  solution.h
//  The_Skyline_Problem
//
//  Created by 中央政治局常委 on 15/10/4.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <queue>
using namespace std;
/*
bool operator< (const pair<int, int> &a, const pair<int, int> &b){
    return a.first < b.first;
}*/
class cmp{
public:
    bool operator () (pair<int , int> & a, pair<int , int> & b){
        if (a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> ret;
        queue<pair<int, int>> bLeft;
        priority_queue<pair<int, int>, vector<pair<int , int>>, cmp> bRight;
        pair<int , int> element;
        multiset<int, greater<int>> level;
        for (auto &each:buildings) {
            element.first = each[0];
            element.second = each[2];
            bLeft.push(element);
            element.first = each[1];
            bRight.push(element);
        }
        
        level.emplace(0);
        int current = 0, pre = 0;
        while (!bLeft.empty() || !bRight.empty()) {
            if (!bLeft.empty() && (bRight.empty() || bLeft.front().first <= bRight.top().first)) {
                element = bLeft.front();
                bLeft.pop();
                level.emplace(element.second);
                current = * level.begin();
                if (current != pre) {
                    if (!ret.empty() && ret.back().first == element.first) {
                        ret.back().second = max(ret.back().second, element.second);
                        pre = current;
                        continue;
                    }
                    ret.push_back(element);
                }
                pre = current;
            }
            else {
                element = bRight.top();
                bRight.pop();
                level.erase(level.find(element.second));
                current = *level.begin();
                if (current != pre) {
                    element.second = current;
                    ret.push_back(element);
                }
                pre = current;
            }
        }
        return ret;
    }
};

#endif /* solution_h */
