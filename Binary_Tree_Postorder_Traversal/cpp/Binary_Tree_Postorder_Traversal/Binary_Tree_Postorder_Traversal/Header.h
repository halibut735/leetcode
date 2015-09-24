//
//  Header.h
//  Binary_Tree_Postorder_Traversal
//
//  Created by 中央政治局常委 on 15/9/23.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <iostream>
#include <iostream>
#include <vector>
#include <fstream>
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
        if(!root)   return ret;
        traversal(root, ret);
        return ret;
    }
private:
    void traversal(TreeNode* root, vector<int> &vec){
        if (root->left) {
            traversal(root->left, vec);
        }
        if (root->right) {
            traversal(root->right, vec);
        }
        vec.push_back(root->val);
    }
};

#endif /* Header_h */
