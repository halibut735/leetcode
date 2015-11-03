//
//  solution.h
//  Flatten_Binary_Tree_to_Linked_List
//
//  Created by 中央政治局常委 on 15/10/28.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
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
    void flatten(TreeNode* root) {
        if (!root) return ;
        pre = NULL;
        inOrder(root);
    }
private:
    TreeNode *pre;
    void inOrder(TreeNode* root){
        TreeNode * tmpLeft = root->left, *tmpRight = root->right;
        if (pre){
            pre->left = NULL;
            pre->right = root;
        }
        pre = root;
        if (tmpLeft) inOrder(tmpLeft);
        if (tmpRight) inOrder(tmpRight);
    }
};
#endif /* solution_h */
