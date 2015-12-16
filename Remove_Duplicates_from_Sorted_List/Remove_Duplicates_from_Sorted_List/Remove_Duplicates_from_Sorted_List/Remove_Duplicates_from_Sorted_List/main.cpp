//
//  main.cpp
//  Remove_Duplicates_from_Sorted_List
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * tmp = head;
        while (tmp && tmp->next) {
            if (tmp->val == tmp->next->val) {
                ListNode * tt = tmp->next;
                tmp->next = tmp->next->next;
                delete tt;
            } else
                tmp = tmp->next;
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
