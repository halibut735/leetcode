//
//  main.cpp
//  Length_of_Last_Word
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); ++ i) {
            if (s[i] != ' ' && (!i || s[i - 1] == ' ')) cnt = 1;
            else if (s[i] != ' ') cnt ++;
        }
        return cnt;
    }
};



int main(int argc, const char * argv[]) {
    Solution test;
    test.lengthOfLastWord("World   ");
    return 0;
}
