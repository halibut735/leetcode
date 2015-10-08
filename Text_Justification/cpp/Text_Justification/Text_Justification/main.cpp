//
//  main.cpp
//  Text_Justification
//
//  Created by 中央政治局常委 on 15/9/27.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "solution.h"
fstream handle("/Users/bingoboy/Downloads/cases.txt");

int main(int argc, const char * argv[]) {
    string tmp;
    int maxLength;
    vector<string> vec;
    Solution sol;
    handle >> maxLength;
    vec.push_back("");
    while (handle >> tmp) {
        vec.push_back(tmp);
    }
    vec = sol.fullJustify(vec, maxLength);
    return 0;
}
