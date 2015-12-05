//
//  main.cpp
//  Course_Schedule
//
//  Created by 中央政治局常委 on 15/11/18.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <set>
using namespace std;

fstream input("/Users/bingoboy/Desktop/in.txt");
fstream output("/Users/bingoboy/Desktop/out.txt");
int main(int argc, const char * argv[]) {
    Solution test;
    int course, tmp1, tmp2;
    vector<pair<int, int>> pre;
    input >> course;
    while (input >> tmp1 >> tmp2) {
        pre.push_back({tmp1, tmp2});
    }
    cout << test.canFinish(course, pre) << endl;
    return 0;
}
