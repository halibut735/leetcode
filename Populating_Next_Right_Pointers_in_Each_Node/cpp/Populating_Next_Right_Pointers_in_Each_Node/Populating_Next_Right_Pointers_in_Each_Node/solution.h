//
//  solution.h
//  Populating_Next_Right_Pointers_in_Each_Node
//
//  Created by 中央政治局常委 on 15/10/22.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode *> que;
        TreeLinkNode *tmp = NULL;
        if (!root) return;
        
        que.push(root);
        que.push(NULL);
        while (!que.empty()) {
            if (tmp) tmp->next = que.front();
            tmp = que.front();
            que.pop();
            if (tmp) {
                if (tmp->left) que.push(tmp->left);
                if (tmp->right) que.push(tmp->right);
            }
            else if (!que.empty()) {
                que.push(NULL);
            }
        }
    }
};
#endif /* solution_h */
