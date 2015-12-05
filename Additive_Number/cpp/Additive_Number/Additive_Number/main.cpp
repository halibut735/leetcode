//
//  main.cpp
//  Additive_Number
//
//  Created by 中央政治局常委 on 15/11/29.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    Solution test;
    string a("999"), b("10"), num("1235813");
    cout << test.isAdditiveNumber(num) << endl;
    return 0;
}
