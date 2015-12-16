//
//  main.cpp
//  Pascal's_Triangle_II
//
//  Created by 中央政治局常委 on 15/12/15.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex + 1);
        int left = 0, right = rowIndex;
        while (left <= right) {
            ret[left] = ret[right] = calculate(left, rowIndex);
            ++ left;
            -- right;
        }
        return ret;
    }
private:
    int calculate(long long a, long long b) {
        long long ret = 1;
        for (int i = 0; i < a; ++ i) {
            ret *= b - i;
            ret /= i + 1;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution test;
    test.getRow(2);
    return 0;
}
