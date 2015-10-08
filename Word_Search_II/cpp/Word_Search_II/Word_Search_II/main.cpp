//
//  main.cpp
//  Word_Search_II
//
//  Created by 中央政治局常委 on 15/9/30.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "solution.h"
using namespace std;
fstream handle("/Users/bingoboy/Downloads/cases.txt");
int main(int argc, const char * argv[]) {
    Solution sol;
    vector<vector<char>> board;
    vector<string> words;
    string word;
    char chr;
    int row, columm;
    handle >> row >> columm;
    for (int i = 0; i < row; ++ i) {
        vector<char> line;
        for (int j = 0; j < columm; ++ j) {
            handle >> chr;
            line.push_back(chr);
        }
        board.push_back(line);
    }
    while (handle >> word) {
        words.push_back(word);
    }
    words = sol.findWords(board, words);
    return 0;
}
