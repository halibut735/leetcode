//
//  main.cpp
//  Game_of_Life
//
//  Created by 中央政治局常委 on 15/10/27.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    Solution test;
    vector<vector<int>> board({{1, 1}, {1, 0}});
    test.gameOfLife(board);
    return 0;
}
