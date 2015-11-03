//
//  solution.h
//  Binary_Tree_Preorder_Traversal
//
//  Created by 中央政治局常委 on 15/10/22.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <fstream>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preOrder(ret, root);
        return ret;
    }
private:
    void preOrder(vector<int> &ret, TreeNode * pos){
        if (pos == NULL) return;
        ret.push_back(pos->val);
        preOrder(ret, pos->left);
        preOrder(ret, pos->right);
    }
};
#endif /* solution_h */
