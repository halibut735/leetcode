//
//  solution.h
//  Max_Points_on_a_Line
//
//  Created by 中央政治局常委 on 15/9/23.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <vector>
#include <string>
using namespace std;


struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};


class Solution {
public:
    int maxPoints(vector<Point>& points) {
        vector<vector<int>> uset(points.size());
        for (int i = 0; i < points.size(); ++ i) {
            vector<int> tmp(points.size());
            uset.push_back(tmp);
        }
        
        return ret;
    }
private:
    int ret;
};

#endif /* solution_h */
