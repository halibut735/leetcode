//
//  main.cpp
//  Validate_Binary_Search_Tree
//
//  Created by 中央政治局常委 on 15/11/17.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    Solution test;
    test.isValidBST(root);
    return 0;
}
