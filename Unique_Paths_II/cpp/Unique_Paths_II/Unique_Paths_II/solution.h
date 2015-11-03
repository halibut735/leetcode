//
//  solution.h
//  Unique_Paths_II
//
//  Created by 中央政治局常委 on 15/10/30.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        long row = obstacleGrid.size(), column = obstacleGrid[0].size();
        if (obstacleGrid[row - 1][column - 1] || obstacleGrid[0][0]) return 0;
        vector<vector<int>> pathCnts = obstacleGrid;
        pathCnts[row - 1][column - 1] = 1;
        for (long i = row - 2; i >= 0; -- i)
            pathCnts[i][column - 1] = !pathCnts[i + 1][column - 1] || obstacleGrid[i][column - 1] ? 0 : 1;
        for (long i = column - 2; i >= 0; -- i)
            pathCnts[row - 1][i] = !pathCnts[row - 1][i + 1] || obstacleGrid[row - 1][i] ? 0 : 1;
        
        for (long i = row - 2; i >= 0; -- i) {
            for (long j = column - 2; j >= 0; -- j) {
                pathCnts[i][j] = pathCnts[i + 1][j] + pathCnts[i][j + 1];
                if (obstacleGrid[i][j]) pathCnts[i][j] = 0;
            }
        }
        
        return pathCnts[0][0];
    }
};
#endif /* solution_h */
