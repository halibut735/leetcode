//
//  main.cpp
//  Power_of_Two
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int imax = 0x40000000;
    bool isPowerOfTwo(int n) {
        //return n > 0 && !(imax % n);
        return n > 0 && !(n & (n - 1));
    }
};

int main(int argc, const char * argv[]) {
    Solution test;
    cout << test.isPowerOfTwo(6) << endl;
    return 0;
}
