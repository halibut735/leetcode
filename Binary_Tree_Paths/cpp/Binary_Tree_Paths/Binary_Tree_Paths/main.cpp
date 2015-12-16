//
//  main.cpp
//  Binary_Tree_Paths
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        string path;
        if (root) dfs(root, to_string(root->val), ret);
        return ret;
    }
private:
    void dfs(TreeNode* root, string path, vector<string> &ret) {
        if (!root->left && !root->right) {
            ret.push_back(path);
            return ;
        }
        if (root->left) {
            dfs(root->left, path + "->" + to_string(root->left->val), ret);
        }
        if (root->right) {
            dfs(root->right, path + "->" + to_string(root->right->val), ret);
        }
    }
};


int main(int argc, const char * argv[]) {
    Solution test;
    return 0;
}
