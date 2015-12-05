//
//  solution.h
//  Maximal_Square
//
//  Created by 中央政治局常委 on 15/11/18.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        long row = matrix.size(), column = matrix[0].size();
        vector<vector<int>> length(row, vector<int>(column));
        int ret = 0;
        for (int i = 0; i < row; ++ i) {
            for (int j = 0; j < column; ++ j) {
                length[i][j] = matrix[i][j] - '0';
                if (i && j && length[i][j]) {
                    int tmp = min(length[i - 1][j], length[i][j - 1]);
                    if (length[i - tmp][j - tmp]) length[i][j] = tmp + 1;
                    else length[i][j] = max(tmp, int(length[i][j]));
                }
                ret = max(ret , int(length[i][j]));
            }
        }
        return ret * ret;
    }
};
#endif /* solution_h */
