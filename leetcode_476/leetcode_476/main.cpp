//
//  main.cpp
//  leetcode_476
//
//  Created by 中央政治局常委 on 2017/3/1.
//  Copyright © 2017年 中央政治局常委. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int tmp = ~0;
        while (num & tmp)
            tmp <<= 1;
        return (~tmp) ^ num;
    }
};

int main(int argc, const char * argv[]) {
    Solution test;
    cout << test.findComplement(5) << endl;
    return 0;
}
