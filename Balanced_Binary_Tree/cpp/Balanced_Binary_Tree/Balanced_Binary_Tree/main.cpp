//
//  main.cpp
//  Balanced_Binary_Tree
//
//  Created by 中央政治局常委 on 15/12/15.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <algorithm>
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
    bool isBalanced(TreeNode* root) {
        int depth = cmp_depth(root);
        return depth != -1;
    }
private:
    int cmp_depth(TreeNode *node) {
        if (!node) return 0;
        int ldepth = cmp_depth(node->left);
        if (ldepth == -1) return -1;
        int rdepth= cmp_depth(node->right);
        if (rdepth == -1) return -1;
        if (abs(ldepth - rdepth) > 1) return -1;
        return max(rdepth, ldepth) + 1;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
