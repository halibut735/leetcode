//
//  solution.h
//  Convert_Sorted_List_to_Binary_Search_Tree
//
//  Created by 中央政治局常委 on 15/10/30.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        for (auto pointer = head; pointer; pointer = pointer->next)
            len ++;
        return dfs(head, len);
    }
private:
    TreeNode * dfs(ListNode* &node, int len){
        if (len < 1 || !node) return NULL;
        int middle = len / 2;
        TreeNode * left = dfs(node, middle);
        TreeNode * ret = new TreeNode(node->val);
        ret->left = left;
        node = node->next;
        if (node) ret->right = dfs(node, len - middle - 1);
        return ret;
    }
};
#endif /* solution_h */

























