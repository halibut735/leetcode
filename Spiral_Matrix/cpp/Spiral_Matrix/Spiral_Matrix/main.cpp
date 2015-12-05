//
//  main.cpp
//  Spiral_Matrix
//
//  Created by 中央政治局常委 on 15/11/18.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


fstream input("/Users/bingoboy/Desktop/in.txt");
int main(int argc, const char * argv[]) {
    int row = 0, column = 0, tmp = 0;
    vector<int> line;
    vector<vector<int>> grid;
    input >> row >> column;
    for (int i = 0; i < row; ++ i) {
        line.clear();
        for (int j = 0; j < column; ++ j) {
            input >> tmp;
            line.push_back(tmp);
        }
        grid.push_back(line);
    }
    Solution test;
    auto haha = test.spiralOrder(grid);
    for (auto each:haha) {
        cout << each << endl;
    }
    return 0;
}
