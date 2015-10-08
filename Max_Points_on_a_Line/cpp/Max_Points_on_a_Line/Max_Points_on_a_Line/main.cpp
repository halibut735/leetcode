//
//  main.cpp
//  Max_Points_on_a_Line
//
//  Created by 中央政治局常委 on 15/9/23.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
//#include "solution.h"
#include "solution2.h"
#include <string>
using namespace std;
ifstream handle("/Users/bingoboy/Downloads/cases.txt");


int main(int argc, const char * argv[]) {
    Solution sol;
    int x, y;
    vector<Point> points;
    while (handle >> x >> y) {
        points.push_back(Point(x, y));
    }
    cout << sol.maxPoints(points) << endl;
    return 0;
}
