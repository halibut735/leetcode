//
//  solution.h
//  Convert_Sorted_Array_to_Binary_Search_Tree
//
//  Created by 中央政治局常委 on 15/10/25.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <fstream>
#include <set>
#include <list>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = NULL;
        if (nums.empty()) return root;
        
        constructTree(root, nums, 0, nums.size());
        return root;
    }
private:
    void constructTree(TreeNode* & node, vector<int>& nums, long start, long end){
        long pos = (start + end) / 2;
        if (start >= end) return ;
        node = new TreeNode(nums[pos]);
        constructTree(node->left, nums, start, pos);
        constructTree(node->right, nums, pos + 1, end);
    }
};
#endif /* solution_h */
