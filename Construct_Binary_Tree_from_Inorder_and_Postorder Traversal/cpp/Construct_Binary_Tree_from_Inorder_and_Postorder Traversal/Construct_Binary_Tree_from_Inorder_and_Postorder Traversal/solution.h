//
//  solution.h
//  Construct_Binary_Tree_from_Inorder_and_Postorder Traversal
//
//  Created by 中央政治局常委 on 15/10/31.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <vector>
#include <iostream>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
private:
    TreeNode * build(vector<int>& inorder, int startIn, int endIn, vector<int>& postorder, int startPost, int endPost){
        if (startIn >= endIn) return NULL;
        int pos = 0, val = postorder[endPost - 1];
        
        TreeNode * ret = new TreeNode(val);
        while (inorder[startIn + pos] != val) pos ++;
        
        ret->left = build(inorder, startIn, startIn + pos, postorder, startPost, startPost + pos);
        ret->right = build(inorder, startIn + pos + 1, endIn, postorder, startPost + pos, endPost - 1);
        return ret;
    }
};
#endif /* solution_h */


































