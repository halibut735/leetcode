//
//  solution.h
//  Set_Matrix_Zeroes
//
//  Created by 中央政治局常委 on 15/10/26.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        vector<bool> row(matrix.size(), false);
        vector<bool> column(matrix[0].size(), false);
        for (int i = 0; i < matrix.size(); ++ i) {
            for (int j = 0; j < matrix[0].size(); ++ j) {
                if (!matrix[i][j]) {
                    row[i] = true;
                    column[j] = true;
                }
            }
        }
        for (int i = 0; i < matrix.size(); ++ i) {
            for (int j = 0; j < matrix[0].size(); ++ j) {
                matrix[i][j] = row[i] || column[j] ? 0 : matrix[i][j];
            }
        }
    }
};
#endif /* solution_h */
