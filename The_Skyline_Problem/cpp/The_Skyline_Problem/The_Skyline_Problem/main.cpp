//
//  main.cpp
//  The_Skyline_Problem
//
//  Created by 中央政治局常委 on 15/10/4.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <set>
#include <map>
#include "solution.h"
using namespace std;

fstream handle("/Users/bingoboy/Downloads/cases.txt");
int main(int argc, const char * argv[]) {
    int left, right, height;
    vector<vector<int>> buildings;
    while (handle >> left >> right >> height) {
        vector<int> each;
        each.push_back(left);
        each.push_back(right);
        each.push_back(height);
        buildings.push_back(each);
    }
    Solution haha;
    haha.getSkyline(buildings);
    return 0;
}
