//
//  solution.h
//  Combination_Sum_II
//
//  Created by 中央政治局常委 on 15/11/26.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        return bfind(candidates, target, 0);
    }
private:
    vector<vector<int>> bfind(vector<int>& candidates, int target, int x) {
        vector<vector<int>> ret;
        if (candidates[x] > target || x == candidates.size()) return ret;
        
        if (binary_search(candidates.begin() + x, candidates.end(), target)) ret.push_back({target});
        for (int i = x; i < candidates.size() - 1; ++ i) {
            if (candidates[i] + candidates[i + 1] > target) break;
            if (i > x && candidates[i] == candidates[i - 1]) continue;
            for (int j = i + 1; j < candidates.size(); ++ j) {
                if (j > i + 1 && candidates[j] == candidates[j - 1]) continue;
                if (candidates[i] + candidates[j] == target) {
                    ret.push_back({candidates[i], candidates[j]});
                    break;
                } else if (candidates[i] + candidates[j] < target) {
                    auto tmp = bfind(candidates, target - candidates[i] - candidates[j], j + 1);
                    for (auto each:tmp) {
                        vector<int> res({candidates[i], candidates[j]});
                        res.insert(res.end(), each.begin(), each.end());
                        ret.push_back(res);
                    }
                } else {
                    break;
                }
            }
        }
        return ret;
    }
    
};
#endif /* solution_h */
