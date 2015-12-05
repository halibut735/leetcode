//
//  main.cpp
//  Combination_Sum_II
//
//  Created by 中央政治局常委 on 15/11/26.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> candidates({1,2,2,2});
    int target = 5;
    Solution test;
    auto tmp = test.combinationSum2(candidates, target);
    for (auto vec:tmp) {
        for (auto each:vec) {
            cout << each << ", ";
        }
        cout << endl;
    }
    return 0;
}
