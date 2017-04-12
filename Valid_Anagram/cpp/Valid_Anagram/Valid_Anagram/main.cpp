//
//  main.cpp
//  Valid_Anagram
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int chr[257] = {};
        if (s.size() != t.size()) return false;
        for (int i = 0; i < s.size(); ++ i) {
            chr[s[i]] ++;
            chr[t[i]] --;
        }
        for (int i = 0; i < 257; ++ i)
            if (chr[i]) return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    string a("a"), b("b");
    Solution sol;
    cout << sol.isAnagram(a, b) << endl;
    return 0;
}
