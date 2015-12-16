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
        bool ret = true;
        depth(root, ret);
        return ret;
    }
private:
    int depth(TreeNode * root, bool &flag) {
        if (!root || !flag) return 0;
        int left = depth(root->left, flag);
        int right = depth(root->right, flag);
        if (left - right > 1 || right - left > 1) flag = false;
        return max(left, right) + 1;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
