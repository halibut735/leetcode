//
//  solution.h
//  Gray_Code
//
//  Created by 中央政治局常委 on 15/10/25.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <bitset>
#include <fstream>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
        for (int i = 0; i < n; ++ i) {
            vector<int> tmp(ret.rbegin(), ret.rend());
            for (auto each:tmp)  ret.push_back(each ^ (1 << i));
        }
        return ret;
    }
};
#endif /* solution_h */
