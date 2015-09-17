//
//  main.cpp
//  Longest_Valid_Parentheses
//
//  Created by 中央政治局常委 on 15/9/16.
//  Copyright (c) 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <fstream>
#if 0
#include "solution.h"
#else
#include "solution2.h"
#endif
using namespace std;

fstream handle("/Users/bingoboy/Downloads/cases.txt");
string cases;
int main(int argc, const char * argv[]) {
    Solution test;
    while (handle >> cases) {
        cout << test.longestValidParentheses(cases) << endl;
    }
    return 0;
}
