//
//  solution.h
//  Spiral_Matrix
//
//  Created by 中央政治局常委 on 15/11/18.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Solution {
public:
    int dirx[4] = {0, 1, 0, -1};
    int diry[4] = {1, 0, -1, 0};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int x = 0, y = 0, dir = 0, cnt = 0;
        if (matrix.empty() || matrix[0].empty()) return ret;
        long row = matrix.size(), column = matrix[0].size();
        vector<vector<bool>> isVisited(row, vector<bool>(column, false));
        
        
        while (cnt < row * column) {
            ret.push_back(matrix[x][y]);
            isVisited[x][y] = true;
            cnt ++;
            x += dirx[dir];
            y += diry[dir];
            if (x < 0 || x >= row || y < 0 || y >= column || isVisited[x][y]) {
                x -= dirx[dir];
                y -= diry[dir];
                dir = ++dir % 4;
                x += dirx[dir];
                y += diry[dir];
            }
        }
        return ret;
    }
};
#endif /* solution_h */
