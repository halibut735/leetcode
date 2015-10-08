//
//  solution2.h
//  Max_Points_on_a_Line
//
//  Created by 中央政治局常委 on 15/9/25.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution2_h
#define solution2_h

#include <map>
#include <unordered_map>
#include <vector>
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
        if (points.size() < 2) {
            return points.size();
        }
        unordered_map<double, int> slope;
        vector<int> vertical(points.size());
        double tmp_slope;
        int ret = 0;
        for (int i = 0; i < points.size(); ++ i) {
            int local_max = 0;
            int same_point = 1;
            for (int j = i + 1; j < points.size(); ++ j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    same_point ++;
                    continue;
                }
                else if (points[i].x == points[j].x) {
                    vertical[i] ++;
                    local_max = vertical[i] > local_max ? vertical[i] : local_max;
                    continue;
                }
                tmp_slope = (points[i].y * 1.0 - points[j].y)/(points[i].x - points[j].x);
                slope[tmp_slope] ++;
                local_max = slope[tmp_slope] > local_max ? slope[tmp_slope] : local_max;
            }
            local_max += same_point;
            ret = local_max > ret ? local_max : ret;
            slope.clear();
        }
        return ret;
    }
};



#endif /* solution2_h */
