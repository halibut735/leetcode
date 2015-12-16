//
//  main.cpp
//  Number_of_1_Bits
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        uint32_t weight = 1;
        for (int i = 0; i < 32; ++ i) {
            ret += (n & weight) ? 1 : 0;
            weight <<= 1;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
