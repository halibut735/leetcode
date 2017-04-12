//
//  main.cpp
//  Lowest_Common_Ancestor_of_a_Binary_Search_Tree
//
//  Created by 中央政治局常委 on 16/3/31.
//  Copyright © 2016年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (true) {
            if (root->val < p->val && root->val < q->val)
                root = root->right;
            else if (root->val > p->val && root->val > q->val)
                root = root->left;
            else return root;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
