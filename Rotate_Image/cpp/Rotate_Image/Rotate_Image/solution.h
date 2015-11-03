//
//  solution.h
//  Rotate_Image
//
//  Created by 中央政治局常委 on 15/10/25.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        vector<vector<int>> ret(matrix);
        
        long n = matrix[0].size();
        for (int i = 0; i < matrix.size(); ++ i) {
            for (int j = 0; j < matrix[0].size(); ++ j) {
                matrix[i][j] = ret[n - 1- j][i];
            }
        }
    }
};
#endif /* solution_h */
