//
//  solution.h
//  N-Queens_II
//
//  Created by 中央政治局常委 on 15/12/1.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string>> ret;
        vector<string> grid(n, string(n, '.'));
        dfs(n, 0, grid, ret);
        return ret.size();
    }
private:
    const int boardlen = 100;
    void dfs(int n, int row, vector<string> &grid, vector<vector<string>> &ret) {
        if (n == row) {
            ret.push_back(grid);
            return;
        }
        for (int i = 0; i < n; ++ i) {
            bool flag = true;
            for (int j = 0; j < row; ++ j)
                if (grid[j][i] == 'Q') flag = false;
            for (int j = 0; j < n; ++ j)
                if (row - abs(i - j) >= 0 && grid[row - abs(i - j)][j] == 'Q') flag = false;
            if (flag) {
                grid[row][i] = 'Q';
                dfs(n, row + 1, grid, ret);
                grid[row][i] = '.';
            }
        }
    }
};
#endif /* solution_h */
