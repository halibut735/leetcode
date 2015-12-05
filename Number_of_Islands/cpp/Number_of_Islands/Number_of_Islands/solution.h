//
//  solution.h
//  Number_of_Islands
//
//  Created by 中央政治局常委 on 15/11/27.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <fstream>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        long row = grid.size(), column = grid[0].size();
        int ret = 0;
        for (int i = 0;i < row ; ++ i) {
            for (int j = 0; j < column; ++ j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++ ret;
                }
            }
        }
        return ret;
    }
private:
    int dirx[4] = {0, 0, 1, -1};
    int diry[4] = {1, -1, 0, 0};
    void dfs(vector<vector<char>>& grid, int x, int y) {
        long row = grid.size(), column = grid[0].size();
        grid[x][y] = 0;
        for (int i = 0; i < 4; ++ i) {
            x += dirx[i];
            y += diry[i];
            if (x >= 0 && x < row && y >= 0 && y < column && grid[x][y] == '1')
                dfs(grid, x, y);
            x -= dirx[i];
            y -= diry[i];
        }
    }
};
#endif /* solution_h */
