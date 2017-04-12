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
        return false;
    }
};
const char * vec[10];
int main(int argc, const char * argv[]) {
    vec = {"hello", "world", "aaa", "bbb", "ccc", "ddd", "eee", "fff", "ggg", "hhh"};
    for (auto each : vec) {
        cout << each << endl;
    }
    return 0;
}
