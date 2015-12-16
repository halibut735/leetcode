//
//  main.cpp
//  LCAofBST
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> pathp, pathq;
        TreeNode * tmp = root, * ret = root;
        while (tmp != p) {
            pathp.push_back(tmp);
            if (p->val < tmp->val) tmp = tmp->left;
            else tmp = tmp->right;
        }
        pathp.push_back(p);
        
        tmp = root;
        while (tmp != q) {
            pathq.push_back(tmp);
            if (q->val < tmp->val) tmp = tmp->left;
            else tmp = tmp->right;
        }
        pathq.push_back(q);
        for (int i = 0; i < pathp.size() && i < pathq.size(); ++ i) {
            if (pathp[i] != pathq[i]) return ret;
            else ret = pathp[i];
        }
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    
    return 0;
}
