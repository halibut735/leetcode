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
        for (; n; ++ ret)
            n &= n - 1;
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    cout << sol.hammingWeight(4294967295) << endl;
    return 0;
}
