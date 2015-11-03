//
//  solution.h
//  Unique_Binary_Search_Trees
//
//  Created by 中央政治局常委 on 15/10/22.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> cnts(n + 1, 0);
        
        cnts[0] = cnts[1] = 1;
        for (int i = 2; i <= n; ++ i) {
            for (int j = 0; j < i; ++ j) {
                cnts[i] += cnts[j] * cnts[i - j - 1];
            }
        }
        return cnts[n];
    }
};
#endif /* solution_h */
