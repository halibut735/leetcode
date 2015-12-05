//
//  main.cpp
//  Permutations_II
//
//  Created by 中央政治局常委 on 15/11/26.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> nums({1, 3, 2});
    Solution test;
    auto tmp = test.permuteUnique(nums);
    for (auto each:tmp) {
        for (auto num:each) {
            cout << num << ", ";
        }
        cout << endl;
    }
    return 0;
}
