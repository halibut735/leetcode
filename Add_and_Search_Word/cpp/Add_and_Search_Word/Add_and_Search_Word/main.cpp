//
//  main.cpp
//  Add_and_Search_Word
//
//  Created by 中央政治局常委 on 15/11/10.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

fstream input("/Users/bingoboy/Desktop/in.txt");
fstream output("/Users/bingoboy/Desktop/out.txt", ios::out | ios::trunc);
int main(int argc, const char * argv[]) {
    string commander, word;
    WordDictionary test;
    while (input >> commander >> word) {
        if (commander == "addWord") {
            test.addWord(word);
        }
        else if (commander == "search") {
            output << test.search(word) << endl;
        }
    }
    return 0;
}
