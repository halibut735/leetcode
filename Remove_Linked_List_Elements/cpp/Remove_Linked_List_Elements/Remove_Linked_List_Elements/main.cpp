//
//  main.cpp
//  Remove_Linked_List_Elements
//
//  Created by 中央政治局常委 on 15/12/16.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};




class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * tmp = new ListNode(0);
        tmp->next = head;
        head = tmp;
        while (tmp->next) {
            if (tmp->next->val == val) {
                ListNode * tt = tmp->next;
                tmp->next = tmp->next->next;
                delete tt;
            } else {
                tmp = tmp->next;
            }
        }
        return head->next;
    }
};




int main(int argc, const char * argv[]) {
    Solution test;
    ListNode * head = new ListNode(1);
    test.removeElements(head, 1);
    return 0;
}
