//
//  solution.h
//  Subsets_II
//
//  Created by 中央政治局常委 on 15/10/30.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        dfs(ret, nums, cur, 0);
        ret.push_back({});
        return ret;
    }
private:
    void dfs(vector<vector<int>>& ret, vector<int>& nums, vector<int>& cur, int index){
        if (cur.size()) ret.push_back(cur);
        if (index == nums.size()) return;
        while (index + 1 < nums.size() && nums[index] == nums[index + 1])
            index ++;
        dfs(ret, nums, cur, index + 1);
        cur.push_back(nums[index]);
        dfs(ret, nums, cur, index + 1);
        cur.pop_back();
    }
};
#endif /* solution_h */
