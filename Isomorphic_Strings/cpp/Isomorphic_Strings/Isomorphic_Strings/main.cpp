//
//  main.cpp
//  Isomorphic_Strings
//
//  Created by 中央政治局常委 on 15/12/16.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        char chs[256] = {}, cht[256] = {};
        for (int i = 0; i < s.size(); ++ i) {
            if (chs[s[i]] && chs[s[i]] != t[i]) return false;
            else chs[s[i]] = t[i];
            if (cht[t[i]] && cht[t[i]] != s[i]) return false;
            else cht[t[i]] = s[i];
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution test;
    cout << test.isIsomorphic("foo", "baa") << endl;
    return 0;
}
