//
//  main.cpp
//  Convert_Sorted_Array_to_Binary_Search_Tree
//
//  Created by 中央政治局常委 on 15/10/25.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <fstream>
#include <set>
#include <list>
#include <vector>
using namespace std;


fstream handle("/Users/bingoboy/Downloads/cases.txt");
int main(int argc, const char * argv[]) {
    vector<int> input;
    Solution test;
    int tmp;
    while (handle >> tmp) {
        input.push_back(tmp);
    }
    test.sortedArrayToBST(input);
    return 0;
}
