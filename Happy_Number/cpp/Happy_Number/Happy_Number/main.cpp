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
        unordered_set<int> table;
        while (n != 1) {
            int next = 0;
            while (n) {
                int tmp = n % 10;
                n /= 10;
                next += tmp * tmp;
            }
            n = next;
            if (table.count(n)) break;
            table.insert(n);
        }
        return n == 1;
    }
};

int main(int argc, const char * argv[]) {
    Solution test;
    cout << test.isHappy(2) << endl;
    return 0;
}
