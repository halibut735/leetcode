//
//  main.cpp
//  Implement_strStr
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) return -1;
        for (int i = 0; i < haystack.size() - needle.size() + 1; ++ i) {
            int j = 0;
            for (j = 0; j < needle.size(); ++ j) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == needle.size()) return i;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    Solution test;
    cout << test.strStr("sfdsfjlsfjklsdjfkl", "999l") << endl;
    return 0;
}
