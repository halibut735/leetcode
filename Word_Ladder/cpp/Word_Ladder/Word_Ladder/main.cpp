//
//  main.cpp
//  Word_Ladder
//
//  Created by 中央政治局常委 on 15/11/17.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <unordered_set>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

fstream input("/Users/bingoboy/Desktop/in.txt");
fstream output("/Users/bingoboy/Desktop/out.txt");
int main(int argc, const char * argv[]) {
    string beginWord, endWord, tmp;
    input >> beginWord >> endWord;
    Solution test;
    unordered_set<string> wordList;
    while (input >> tmp) {
        wordList.insert(tmp);
    }
    cout << test.ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}
