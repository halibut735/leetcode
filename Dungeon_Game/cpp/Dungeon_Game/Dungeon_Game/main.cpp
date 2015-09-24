//
//  main.cpp
//  Dungeon_Game
//
//  Created by 中央政治局常委 on 15/9/17.
//  Copyright (c) 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
//#include "solution.h"
#include "solution2.h"
#include <vector>
#include <fstream>
using namespace std;
fstream handle("/Users/bingoboy/Downloads/cases.txt");

int main(int argc, const char * argv[]) {
    vector<vector<int>>  cases;
    int row, column, tmp;
    handle >> row >> column;
    for (int i = 0; i < row; ++i) {
        vector<int> vec;
        for (int j = 0; j < column; ++ j) {
            handle >> tmp;
            vec.push_back(tmp);
        }
        cases.push_back(vec);
    }
    Solution sol;
    sol.print_vec(cases);
    cout << sol.calculateMinimumHP(cases) << endl;
    return 0;
}
