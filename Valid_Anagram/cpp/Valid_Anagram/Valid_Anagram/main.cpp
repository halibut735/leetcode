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
        if (s.size() != t.size()) return false;
        unordered_map<char, int> cnts;
        for (int i = 0; i < s.size(); ++ i) {
            cnts[s[i]] ++;
            cnts[t[i]] --;
        }
        for (auto each : cnts) if (each.second) return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
