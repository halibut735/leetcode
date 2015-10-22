//
//  main.cpp
//  Evaluate_Reverse_Polish_Notation
//
//  Created by 中央政治局常委 on 15/10/15.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "solution.h"
using namespace std;


int main(int argc, const char * argv[]) {
    Solution test;
    vector<string> tokens;
    tokens.push_back("0");
    tokens.push_back("3");
    tokens.push_back("/");
    test.evalRPN(tokens);
    return 0;
}
