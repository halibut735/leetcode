//
//  main.cpp
//  Valid_Palindrome
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int ll = 0, rr = (int) s.size() - 1;
        for (char & each : s) if (each <= 'Z' && each >= 'A') each = 'a' + each - 'A';
        while (ll < rr) {
            while (ll <= rr && !isalphanumeric(s[ll])) ll ++;
            while (ll <= rr && !isalphanumeric(s[rr])) rr --;
            //cout << s[ll] << s[rr] << endl;
            if (ll >= rr) return true;
            if (s[ll] != s[rr]) return false;
            ll ++;
            rr --;
        }
        return true;
    }
private:
    bool isalphanumeric(char a) {
        return (a <= 'z' && a >= 'a') || (a <= '9' && a >= '0');
    }
};


int main(int argc, const char * argv[]) {
    Solution test;
    cout << test.isPalindrome("!!!") << endl;
    return 0;
}
