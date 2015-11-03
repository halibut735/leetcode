//
//  solution.h
//  Spiral_Matrix_II
//
//  Created by 中央政治局常委 on 15/10/25.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int directionx[] = {0, 1, 0, -1, 0};
        int directiony[] = {1, 0, -1, 0, 0};
        int posX = 0, posY = 0;
        int dir = 4;
        for (int i = 1; i <= n * n; ++ i) {
            ret[posX += directionx[dir]][posY += directiony[dir]] = i;
            switch (dir) {
                case 0:
                    if (posY + 1 == n || ret[posX][posY + 1]) dir ++;
                    break;
                    
                case 1:
                    if (posX + 1 == n || ret[posX + 1][posY]) dir ++;
                    break;
                    
                case 2:
                    if (!posY || ret[posX][posY - 1]) dir ++;
                    break;
                    
                case 3:
                    if (ret[posX - 1][posY]) dir = 0;
                    break;
                    
                default:
                    dir = 0;
                    break;
            }
        }
        return ret;
    }
};
#endif /* solution_h */
