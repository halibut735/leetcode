//
//  solution2.h
//  Dungeon_Game
//
//  Created by 中央政治局常委 on 15/9/18.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution2_h
#define solution2_h

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        vector<vector<int>>::size_type row = dungeon.size();
        vector<int>::size_type column = dungeon[0].size();
        init_vec(best_gauge, column, row);
        tmp = 1 - dungeon[row - 1][column - 1];
        best_gauge[row - 1][column - 1] = tmp > 0 ? tmp : 1;
        for (long i = row - 1; i >= 0; --i) {
            for (long j = column -1; j >= 0; --j) {
                if (i - 1 >= 0) {
                    tmp = best_gauge[i][j] - dungeon[i - 1][j];
                    tmp = tmp > 0 ? tmp : 1;
                    if (best_gauge[i - 1][j] == 0 || best_gauge[i - 1][j] > tmp) {
                        best_gauge[i - 1][j] = tmp;
                    }
                }
                if (j - 1 >= 0) {
                    tmp = best_gauge[i][j] - dungeon[i][j - 1];
                    tmp = tmp > 0 ? tmp : 1;
                    if (best_gauge[i][j - 1] == 0 || best_gauge[i][j - 1] > tmp) {
                        best_gauge[i][j - 1] = tmp;
                    }
                }
            }
        }
        print_vec(best_gauge);
        return best_gauge[0][0];
    }
    void init_vec(vector<vector<int>>& aa, int x, int y){
        for (int i = 0; i < y; ++i) {
            vector<int> tmp(x);
            aa.push_back(tmp);
        }
    }
    void print_vec(vector<vector<int>>& aa){
        vector<vector<int>>::size_type row = aa.size();
        vector<int>::size_type column = aa[0].size();
        for (long i = 0; i < row; ++i) {
            for (long j = 0; j < column; ++j) {
                cout << aa[i][j] << " ";
            }
            cout << endl;
        }
    }
private:
    vector<vector<int>> best_gauge;
    int tmp;
};


#endif /* solution2_h */
