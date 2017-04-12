//
//  main.cpp
//  Excel_Sheet_Column_Number
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0, mul = 1;
        for (long i = s.size() - 1; i >= 0; -- i) {
            ret += mul * (s[i] - 'A' + 1);
            mul *= 26;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution test;
    cout << test.titleToNumber("AA") << endl;
    return 0;
}
