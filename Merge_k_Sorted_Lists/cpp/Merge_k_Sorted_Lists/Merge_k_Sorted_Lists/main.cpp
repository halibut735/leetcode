//
//  main.cpp
//  Merge_k_Sorted_Lists
//
//  Created by 中央政治局常委 on 15/9/22.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
//#include "solution.h"
#include "solution2.h"
using namespace std;

fstream handle("/Users/bingoboy/Downloads/cases.txt");
int main(int argc, const char * argv[]) {
    int cnt = 0;
    int val, i = 0;
    stringstream convert;
    string line;
    handle >> cnt;
    vector<ListNode*> cases(cnt);
    ListNode* pos;
    while (getline(handle, line)) {
        convert << line;
        pos = cases[i++];
        while (convert >> val) {
            pos = new ListNode(val);
            pos = pos->next;
        }
    }
    return 0;
}
