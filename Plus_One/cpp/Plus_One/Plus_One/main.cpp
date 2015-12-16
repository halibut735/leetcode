//
//  main.cpp
//  Plus_One
//
//  Created by 中央政治局常委 on 15/12/9.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; -- i) {
            if (!carry) return digits;
            digits[i] = digits[i] + carry;
            carry = digits[i] == 10 ? 1 : 0;
            digits[i] = digits[i] == 10 ? 0 : digits[i];
        }
        if (carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
