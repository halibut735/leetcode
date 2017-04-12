//
//  main.cpp
//  Power_of_Three
//
//  Created by 中央政治局常委 on 16/1/14.
//  Copyright © 2016年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        int exp = round((log(n) / log(3)));
        return pow(3, exp) == n;
    }
};


int main(int argc, const char * argv[]) {
    Solution test;
    cout << test.isPowerOfThree(243) << endl;
    return 0;
}
