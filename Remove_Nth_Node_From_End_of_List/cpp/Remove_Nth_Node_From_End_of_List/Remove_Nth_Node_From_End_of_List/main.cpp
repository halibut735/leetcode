//
//  main.cpp
//  Remove_Nth_Node_From_End_of_List
//
//  Created by 中央政治局常委 on 15/12/9.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        n ++;
        ListNode * tmp = new ListNode(0), * last = tmp;
        tmp->next = head;
        head = tmp;
        while (n --) {
            last = last->next;
        }
        while (last) {
            tmp = tmp->next;
            last = last->next;
        }
        last = tmp->next;
        tmp->next = tmp->next->next;
        delete last;
        return head->next;
    }
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
