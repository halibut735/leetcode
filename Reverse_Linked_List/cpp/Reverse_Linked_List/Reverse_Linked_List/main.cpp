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
        typedef ListNode * pListNode;
        pListNode cur = head, nnode = NULL;
        while (cur && (nnode = cur->next)) {
            cur->next = nnode->next;
            nnode->next = head;
            head = nnode;
        }
        return head;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
