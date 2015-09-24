//
//  solution2.h
//  Binary_Tree_Postorder_Traversal
//
//  Created by 中央政治局常委 on 15/9/23.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution2_h
#define solution2_h
#include <iostream>
#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <sstream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root)
            return ret;
        stack<TreeNode*> stk;
        TreeNode * tmp;
        stk.push(root);
        while (!stk.empty()) {
            tmp = stk.top();
            if (!tmp->right && !tmp->left) {
                ret.push_back(tmp->val);
                stk.pop();
            }
            if (tmp->right) {
                stk.push(tmp->right);
            }
            if (tmp->left) {
                stk.push(tmp->left);
            }
            tmp->left = tmp->right = NULL;
        }
        return ret;
    }
private:
};



#endif /* solution2_h */
