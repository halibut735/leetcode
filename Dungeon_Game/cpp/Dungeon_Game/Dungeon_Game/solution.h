//
//  solution.h
//  Dungeon_Game
//
//  Created by 中央政治局常委 on 15/9/17.
//  Copyright (c) 2015年 中央政治局常委. All rights reserved.
//

#ifndef Dungeon_Game_solution_h
#define Dungeon_Game_solution_h

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        init_vec(present_gauge, dungeon[0].size(), dungeon.size());
        ret = INT_MIN;
        dfs(dungeon, 0, 0, 0, 0);
        if (ret >= 0) {
            ret = 0;
        }
        else{
            ret = -1 * ret + 1;
        }
        
        return ret;
    }
    
    void dfs(vector<vector<int>>& dungeon, int hp, int min_hp, int x, int y){
        int tmp = dungeon[y][x] + hp;
        present_gauge[y][x] = tmp > present_gauge[y][x]? tmp : present_gauge[y][x];
        int min_gauge = present_gauge[y][x] < min_hp ? present_gauge[y][x] : min_hp;
        if (x == dungeon[0].size() -1 && y == dungeon.size() -1) {
            ret = min_gauge > ret? min_gauge: ret;
        }
        if (min_gauge < ret) {
            return ;
        }
        if (dungeon[0].size() >  x+1) {
            dfs(dungeon, present_gauge[y][x], min_gauge, x+1, y);
        }
        if (dungeon.size() > y+1) {
            dfs(dungeon, present_gauge[y][x], min_gauge, x, y+1);
        }
    }
    void init_vec(vector<vector<int>>& aa, int x, int y){
        for (int i = 0; i < y; ++i) {
            vector<int> tmp(x, INT_MIN);
            aa.push_back(tmp);
        }
    }
private:
    vector<vector<int>> present_gauge;
    int ret;
};
#endif
