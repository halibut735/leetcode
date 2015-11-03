//
//  main.cpp
//  Unique_Paths_II
//
//  Created by 中央政治局常委 on 15/10/30.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    Solution test;
    vector<vector<int>> grid({{0, 0}, {1, 1}, {0, 0}});
    test.uniquePathsWithObstacles(grid);
    return 0;
}
