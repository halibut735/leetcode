//
//  solution.h
//  Triangle
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
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty()) return 0;
        int row = triangle.size();
        for (int i = row - 2; i >= 0; -- i) {
            for (int j = 0; j < i + 1; ++ j) {
                triangle[i][j] = triangle[i][j] + min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};
#endif /* solution_h */
