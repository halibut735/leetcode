//
//  main.cpp
//  Simplify_Path
//
//  Created by 中央政治局常委 on 15/11/18.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <set>
using namespace std;


fstream input("/Users/bingoboy/Desktop/in.txt");
fstream output("/Users/bingoboy/Desktop/out.txt");
int main(int argc, const char * argv[]) {
    string path;
    Solution test;
    input >> path;
    cout << test.simplifyPath(path) << endl;
    return 0;
}
