//
//  solution.h
//  Serialize_and_Deserialize_Binary_Tree
//
//  Created by 中央政治局常委 on 15/11/28.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret, none("#");
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            auto tmp = que.front();
            que.pop();
            ret += tmp ? to_string(tmp->val) + "," : none + ",";
            if (tmp) que.push(tmp->left);
            if (tmp) que.push(tmp->right);
        }
        return ret;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int start = 0, num = 0, cnt = 1;
        queue<TreeNode *> que;
        TreeNode *root = NULL, *tmp = NULL;
        for (int i = 0; i < data.size(); ++ i) {
            if (data[i] == ',') {
                if (data[i - 1] == '#') {
                    if (cnt % 2) que.pop();
                } else {
                    num = stoi(data.substr(start, i - start));
                    tmp = new TreeNode(num);
                    if (que.empty()) root = tmp;
                    else {
                        TreeNode *tmp1 = que.front();
                        if (cnt % 2) {
                            tmp1->right = tmp;
                            que.pop();
                        } else {
                            tmp1->left = tmp;
                        }
                    }
                    que.push(tmp);
                }
                start = i + 1;
                cnt ++;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
#endif /* solution_h */
