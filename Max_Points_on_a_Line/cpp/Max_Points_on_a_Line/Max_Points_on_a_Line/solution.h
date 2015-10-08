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
        if (points.size() < 3) {
            return points.size();
        }
        int ret = 0;
        vector<int> pre(points.size());
        for (int i = 0; i < points.size(); ++ i) {
            pre[i] = i;
        }
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i+1; j < points.size(); ++j) {
                for (int k = j+1; k < points.size(); ++k) {
                    if (is_a_set(points[i], points[j], points[k])) {
                        join(i, j, pre);
                        join(j, k, pre);
                    }
                }
            }
        }
        vector<int> cnt(points.size());
        for (int i = 0; i < points.size(); ++i) {
            int tmp = find(i, pre);
            cnt[tmp] ++;
            if (cnt[tmp] > ret) {
                ret = cnt[tmp];
            }
        }
        if (ret == 1) {
            ret ++;
        }
        return ret;
    }
private:
    bool is_a_set(const Point &a, const Point &b, const Point &c){
        long long tmp1 = (long long)(c.x - a.x) * (c.y - b.y);
        long long tmp2 = (long long)(c.x - b.x) * (c.y - a.y);
        return tmp1 == tmp2;
    }
    int find(int k, vector<int> & pre){
        int root = k;
        while (pre[root] != root) {
            root = pre[root];
        }
        int tmp = k;
        while (pre[k] != root) {
            tmp = pre[k];
            pre[k] = root;
            k = tmp;
        }
        return root;
    }
    void join(int x, int y, vector<int> & pre){
        int rootx = find(x, pre);
        int rooty = find(y, pre);
        if (rootx != rooty) {
            pre[rootx] = rooty;
        }
    }
};

#endif /* solution_h */
