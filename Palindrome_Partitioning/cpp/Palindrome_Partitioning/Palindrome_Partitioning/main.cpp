//
//  main.cpp
//  Palindrome_Partitioning
//
//  Created by 中央政治局常委 on 15/11/25.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;


int main(int argc, const char * argv[]) {
    Solution test;
    string str("aaba");
    auto ret = test.partition(str);
    for (auto eachx:ret) {
        for (auto eachy:eachx) {
            cout << eachy << ", ";
        }
        cout << endl;
    }
    return 0;
}
