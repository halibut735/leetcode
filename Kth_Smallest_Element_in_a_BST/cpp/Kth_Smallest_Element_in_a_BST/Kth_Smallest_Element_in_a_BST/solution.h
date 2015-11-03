//
//  solution.h
//  Kth_Smallest_Element_in_a_BST
//
//  Created by 中央政治局常委 on 15/10/25.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
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
    int kthSmallest(TreeNode* root, int k) {
        int ret = 0;
        inorder(root, k, ret);
        return ret;
    }
    
private:
    int inorder(TreeNode* root, int k, int &val){
        int cnt = 0;
        if (root->left) cnt += inorder(root->left, k, val);
        cnt ++;
        if (cnt == k)
            val = root->val;
        if (!root->left && !root->right) return 1;
        if (root->right && cnt < k) cnt += inorder(root->right, k - cnt, val);
        return cnt;
    }
};
#endif /* solution_h */
