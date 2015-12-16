//
//  main.cpp
//  Symmetric_Tree
//
//  Created by 中央政治局常委 on 15/12/14.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <algorithm>
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return dfs(root->left, root->right);
    }
private:
    bool dfs(TreeNode *left, TreeNode *right) {
        if (!left || !right) return left == right;
        return left->val == right->val && dfs(left->left, right->right) && dfs(left->right, right->left);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
