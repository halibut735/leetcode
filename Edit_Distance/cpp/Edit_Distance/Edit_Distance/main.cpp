//
//  main.cpp
//  Edit_Distance
//
//  Created by 中央政治局常委 on 15/12/5.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    string str1("spartan"), str2("part");
    Solution test;
    cout << test.minDistance(str1, str2) << endl;
    return 0;
}
