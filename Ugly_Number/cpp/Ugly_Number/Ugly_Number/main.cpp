//
//  main.cpp
//  Ugly_Number
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        while (num && !(num % 2)) {
            num /= 2;
        }
        while (num && !(num % 3)) {
            num /= 3;
        }
        while (num && !(num % 5)) {
            num /= 5;
        }
        return num == 1;
    }
};

int main(int argc, const char * argv[]) {
    Solution test;
    cout << test.isUgly(5) << endl;
    return 0;
}
