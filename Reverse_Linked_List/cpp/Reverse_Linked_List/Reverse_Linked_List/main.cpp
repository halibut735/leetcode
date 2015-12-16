//
//  main.cpp
//  Reverse_Linked_List
//
//  Created by 中央政治局常委 on 15/12/8.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode * pos = new ListNode(0), * tmp = 0;
        pos->next = head;
        head = pos;
        pos = pos->next;
        while (pos->next) {
            tmp = pos->next;
            pos->next = pos->next->next;
            tmp->next = head->next;
            head->next = tmp;
        }
        return head->next;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
