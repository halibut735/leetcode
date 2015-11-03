//
//  solution.h
//  Game_of_Life
//
//  Created by 中央政治局常委 on 15/10/27.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) return ;
        vector<vector<int>> ret = board;
        int deaths = 0, lives = 0;
        long m = board.size(), n = board[0].size();
        int dirx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int diry[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < ret.size(); ++ i) {
            for (int j = 0; j < ret[0].size(); ++ j) {
                deaths = lives = 0;
                for (int k = 0; k < 8; ++ k) {
                    if (i + dirx[k] >= 0 && i + dirx[k] < m && j + diry[k] >= 0 && j + diry[k] < n)
                        ret[i + dirx[k]][j + diry[k]] ? lives ++ : deaths ++;
                }
                if (ret[i][j]) {
                    board[i][j] = (lives == 2 || lives == 3) ? 1 : 0;
                }
                else {
                    board[i][j] = lives == 3 ? 1 : 0;
                }
            }
        }
    }
};
#endif /* solution_h */
