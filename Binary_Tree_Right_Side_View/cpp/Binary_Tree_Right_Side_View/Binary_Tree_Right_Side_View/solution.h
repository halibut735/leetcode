//
//  solution.h
//  Binary_Tree_Right_Side_View
//
//  Created by 中央政治局常委 on 15/10/28.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <list>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode *> que;
        TreeNode * tmp = NULL, * pre = NULL;
        if (!root) return ret;
        
        que.push(root);
        que.push(NULL);
        while (!que.empty()) {
            tmp = que.front();
            que.pop();
            if (tmp) {
                if (tmp->left) que.push(tmp->left);
                if (tmp->right) que.push(tmp->right);
            }
            else {
                if (!que.empty())
                    que.push(NULL);
                ret.push_back(pre->val);
            }
            pre = tmp;
        }
        return ret;
    }
};
#endif /* solution_h */
