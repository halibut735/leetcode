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
    bool isPowerOfTwo(int n) {
        if (n < 1) return false;
        while (n > 1) {
            if (n % 2) return false;
            n /= 2;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution test;
    cout << test.isPowerOfTwo(4) << endl;
    return 0;
}
