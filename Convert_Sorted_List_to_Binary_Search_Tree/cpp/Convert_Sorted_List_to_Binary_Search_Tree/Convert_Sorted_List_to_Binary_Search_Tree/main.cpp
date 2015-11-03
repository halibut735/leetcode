//
//  main.cpp
//  Convert_Sorted_List_to_Binary_Search_Tree
//
//  Created by 中央政治局常委 on 15/10/30.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include "solution.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    Solution test;
    fstream handle("/Users/bingoboy/Desktop/cases.txt");
    int tmp;
    handle >> tmp;
    ListNode * head = new ListNode(tmp), * pointer = head;
    while (handle >> tmp) {
        pointer->next = new ListNode(tmp);
        pointer = pointer->next;
    }
    test.sortedListToBST(head);
    return 0;
}
