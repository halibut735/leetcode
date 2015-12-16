//
//  main.cpp
//  Factorial_Trailing_Zeroes
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        long fivetimes = 5, ret = 0;
        while (n / fivetimes && fivetimes > 0) {
            ret += n / fivetimes;
            fivetimes *= 5;
        }
        return ret;
    }
};


int main(int argc, const char * argv[]) {
    Solution test;
    cout << test.trailingZeroes(2147483647) << endl;
    return 0;
}
