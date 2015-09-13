//
//  main.cpp
//  Merge-Intervals
//
//  Created by 中央政治局常委 on 15/9/13.
//  Copyright (c) 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "solution.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Solution aa;
    vector<Interval> test;
    int tmp1, tmp2;
    
    fstream file_handle("/Users/bingoboy/projects/github/leetcode/Merge_Intervals/cpp/Merge-Intervals/Merge-Intervals/cases.txt");
    while (file_handle >> tmp1 >> tmp2) {
        test.push_back(Interval(tmp1, tmp2));
    }
    aa.merge(test);
    print_vec(aa.ret);
    return 0;
}
