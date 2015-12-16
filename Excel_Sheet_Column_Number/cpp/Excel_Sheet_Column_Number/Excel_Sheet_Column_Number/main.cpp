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
        int ret = 0;
        for (int i = 0; i < s.size(); ++ i) {
            ret *= 26;
            ret += s[i] - 'A' + 1;
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution test;
    cout << test.titleToNumber("AA") << endl;
    return 0;
}
