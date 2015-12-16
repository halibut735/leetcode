//
//  main.cpp
//  Reverse_Bits
//
//  Created by 中央政治局常委 on 15/12/15.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t flag = 1 << 31, ret = 0;
        for (int i = 0; i < 32; ++ i) {
            ret |= (n & flag ? 1 : 0) << i;
            flag >>= 1;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution test;
    test.reverseBits(43261596);
    return 0;
}
