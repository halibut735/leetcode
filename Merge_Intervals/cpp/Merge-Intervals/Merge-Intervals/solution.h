//
//  solution.h
//  Merge-Intervals
//
//  Created by 中央政治局常委 on 15/9/13.
//  Copyright (c) 2015年 中央政治局常委. All rights reserved.
//

#ifndef Merge_Intervals_solution_h
#define Merge_Intervals_solution_h

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

void print_vec(vector<Interval> &a){
    for (vector<Interval>::iterator it = a.begin(); it != a.end(); ++it) {
        cout << "the start: " << it->start << "\tthe end: " << it->end << endl;
    }
}

bool operator<(const Interval &a, const Interval &b){
    if (a.start < b.start)
        return true;
    if(a.start == b.start)
        return a.end > b.end?true:false;
    return false;
}

class Solution {
public:
    vector<Interval> ret;
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end());
        for (vector<Interval>::iterator it = intervals.begin(); it != intervals.end(); ++ it) {
            add_base = it;
            while ((it+1) != intervals.end() && add_base->end >= (it+1)->start) {
                tmp = (it+1)->end;
                ++ it;
                add_base->end = it->end > add_base->end?it->end:add_base->end;
            }
            ret.push_back(*add_base);
        }
        return ret;
    }
    
private:
    vector<Interval>::iterator add_base;
    int tmp;
};

#endif
