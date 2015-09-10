//
//  main.cpp
//  Rotate_Array
//
//  Created by 中央政治局常委 on 15/9/10.
//  Copyright (c) 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
#include "solution.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Solution test;
    vector<int> cases;
    for (int i = 0; i < 100; ++i) {
        cases.push_back(i);
    }
    test.print_vector(cases);
    test.rotate(cases, 5);
    //test.print_vector(cases);
    return 0;
}
