//
//  main.cpp
//  Trapping_Rain_Water
//
//  Created by 中央政治局常委 on 15/11/30.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> vec({5,2,1,2,1,5});
    Solution test;
    cout << test.trap(vec) << endl;
    return 0;
}
