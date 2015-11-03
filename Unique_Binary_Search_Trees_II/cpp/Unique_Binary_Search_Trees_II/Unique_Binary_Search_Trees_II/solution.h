//
//  solution.h
//  Unique_Binary_Search_Trees_II
//
//  Created by 中央政治局常委 on 15/10/29.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        auto a = generate(1, n);
        return a;
    }
private:
    vector<TreeNode*> generate(int start, int end){
        vector<TreeNode*> ret, left, right;
        if (start > end) {
            ret.push_back(NULL);
            return ret;
        }
        else if (start == end) {
            ret.push_back(new TreeNode(start));
            return ret;
        }
        for (int i = start; i <= end; ++ i) {
            left = generate(start, i - 1);
            right = generate(i + 1, end);
            for (auto eachl:left) {
                for (auto eachr:right) {
                    TreeNode * tmp = new TreeNode(i);
                    tmp->left = eachl;
                    tmp->right = eachr;
                    ret.push_back(tmp);
                }
            }
        }
        return ret;
    }
};
#endif /* solution_h */
