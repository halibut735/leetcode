//
//  solution.h
//  Lowest_Common_Ancestor_of_a_Binary_Tree
//
//  Created by 中央政治局常委 on 15/10/31.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * answer = NULL;
        if (!root) return answer;
        findAns(root, p, q, answer);
        return answer;
    }
private:
    int findAns(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &answer) {
        if (answer) return 3;
        int ret = 0;
        if (root->left) ret |= findAns(root->left, p, q, answer);
        if (root->right) ret |= findAns(root->right, p, q, answer);
        ret |= root == p ? 1 : 0;
        ret |= root == q ? 2 : 0;
        if (!answer && ret == 3)
            answer = root;
        return ret;
    }
};
#endif /* solution_h */



