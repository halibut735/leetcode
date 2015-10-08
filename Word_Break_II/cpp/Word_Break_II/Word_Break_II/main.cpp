//
//  main.cpp
//  Word_Break_II
//
//  Created by 中央政治局常委 on 15/10/6.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
#include "solution.h"
using namespace std;

fstream handle("/Users/bingoboy/Downloads/cases.txt");
int main(int argc, const char * argv[]) {
    string s, tmp;
    unordered_set<string> wordDict;
    Solution test;
    handle >> s;
    while (handle >> tmp) {
        wordDict.emplace(tmp);
    }
    test.wordBreak(s, wordDict);
    return 0;
}
