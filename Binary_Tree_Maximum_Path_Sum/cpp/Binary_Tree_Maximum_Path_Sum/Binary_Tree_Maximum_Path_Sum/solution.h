//
//  solution.h
//  Binary_Tree_Maximum_Path_Sum
//
//  Created by 中央政治局常委 on 15/12/5.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <fstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;
        int ret = root->val;
        if (root) postorder(root, ret);
        return ret;
    }
private:
    int postorder(TreeNode* root, int &global) {
        int ll = 0, rr = 0, ret = 0, local = 0;
        ll = root->left ? postorder(root->left, global) : 0;
        rr = root->right ? postorder(root->right, global) : 0;
        ret = root->val + max(0, max(ll, rr));
        local = root->val + max(0, ll) + max(0, rr);
        global = max(local, global);
        return ret;
    }
};




#endif /* solution_h */
