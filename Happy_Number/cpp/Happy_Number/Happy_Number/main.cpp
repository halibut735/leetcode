//
//  main.cpp
//  Happy_Number
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> nums;
        while (true) {
            if (n == 1) return true;
            if (nums.count(n)) return false;
            nums.insert(n);
            n = generate(n);
        }
    }
    inline int generate(int a) {
        int ret = 0;
        while (a) {
            ret += (a % 10) * (a % 10);
            a /= 10;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution test;
    cout << test.isHappy(19) << endl;
    return 0;
}
