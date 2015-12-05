//
//  solution.h
//  Validate_Binary_Search_Tree
//
//  Created by 中央政治局常委 on 15/11/17.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> val;
        inOrder(root, val);
        if (val.empty()) return true;
        int pre = val[0];
        for (int i = 1; i < val.size(); ++ i) {
            if (pre >= val[i]) return false;
            pre = val[i];
        }
        return true;
    }
    void inOrder(TreeNode* root, vector<int> &val) {
        if (root == NULL) return;
        inOrder(root->left, val);
        val.push_back(root->val);
        inOrder(root->right, val);
    }
};
#endif /* solution_h */
