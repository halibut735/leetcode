//
//  main.cpp
//  Candy
//
//  Created by 中央政治局常委 on 15/9/13.
//  Copyright (c) 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "header.h"

using namespace std;
fstream src("/Users/bingoboy/Downloads/cases.txt");
int tmp;

int main(int argc, const char * argv[]) {
    Solution haha;
    vector<int> cases;
    while (src >> tmp) {
        cases.push_back(tmp);
    }
    haha.candy(cases);
    return 0;
}
