//
//  main.cpp
//  Binary_Tree_Level_Order_Traversal_II
//
//  Created by 中央政治局常委 on 15/12/15.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>





class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode *> que;
        vector<vector<int>> ret;
        vector<int> level;
        if (!root) return ret;
        que.push(root);
        que.push(NULL);
        while (!que.empty()) {
            TreeNode * tmp = que.front();
            que.pop();
            if (tmp) {
                level.push_back(tmp->val);
                if (tmp->left) que.push(tmp->left);
                if (tmp->right) que.push(tmp->right);
            } else if (1) {
                if (!que.empty()) que.push(NULL);
                ret.push_back(level);
                level.clear();
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
