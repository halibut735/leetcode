//
//  main.cpp
//  Construct_Binary_Tree_from_Inorder_and_Postorder Traversal
//
//  Created by 中央政治局常委 on 15/10/31.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    Solution test;
    vector<int> inOrder({-1});
    vector<int> postOrder({-1});
    test.buildTree(inOrder, postOrder);
    return 0;
}
