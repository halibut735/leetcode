//
//  main.cpp
//  Merge_two_Sorted_Lists
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

/**
 * Definition for singly-linked list. */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0), * tmp = &head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tmp = tmp->next = l1;
                l1 = l1->next;
            } else {
                tmp = tmp->next = l2;
                l2 = l2->next;
            }
        }
        tmp->next = l1 ? l1 : l2;
        return head.next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
