//
//  main.cpp
//  Remove_Invalid_Parentheses
//
//  Created by 中央政治局常委 on 15/12/7.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string s(")(f");
    Solution test;
    test.removeInvalidParentheses(s);
    return 0;
}
