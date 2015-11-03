//
//  solution.h
//  Minimum_Path_Sum
//
//  Created by 中央政治局常委 on 15/10/25.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        for (int i = 0; i < grid.size(); ++ i) {
            for (int j = 0; j < grid[0].size(); ++ j) {
                if (!i && !j) continue;
                if (!i)
                    grid[0][j] = grid[0][j - 1] + grid[0][j];
                else if (!j)
                    grid[i][0] = grid[i - 1][0] + grid[i][0];
                else
                    grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};
#endif /* solution_h */
