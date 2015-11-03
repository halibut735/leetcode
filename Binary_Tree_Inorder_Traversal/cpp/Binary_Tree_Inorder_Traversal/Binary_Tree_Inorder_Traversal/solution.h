//
//  solution.h
//  Binary_Tree_Inorder_Traversal
//
//  Created by 中央政治局常委 on 15/10/22.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <string>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        inOrder(ret, root);
        return ret;
    }
private:
    void inOrder(vector<int> &ret, TreeNode* pos){
        if (pos == NULL) return ;
        inOrder(ret, pos->left);
        ret.push_back(pos->val);
        inOrder(ret, pos->right);
    }
};
#endif /* solution_h */
