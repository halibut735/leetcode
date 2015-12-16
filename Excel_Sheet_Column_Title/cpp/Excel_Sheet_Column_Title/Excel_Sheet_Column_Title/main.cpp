//
//  main.cpp
//  Excel_Sheet_Column_Title
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        while (n) {
            int tmp = (n - 1) % 26;
            ret.push_back('A' + tmp);
            n = (n - 1) / 26;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
