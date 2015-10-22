//
//  main.cpp
//  Substring_with_Concatenation_of_All_Words
//
//  Created by 中央政治局常委 on 15/10/21.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <set>
#include <fstream>
using namespace std;


fstream handle("/Users/bingoboy/Downloads/cases.txt");
int main(int argc, const char * argv[]) {
    Solution test;
    vector<string> words;
    string s, word;
    handle >> s;
    while (handle >> word) {
        words.push_back(word);
    }
    test.findSubstring(s, words);
    return 0;
}
