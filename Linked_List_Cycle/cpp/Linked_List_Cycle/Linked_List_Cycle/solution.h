//
//  solution.h
//  Linked_List_Cycle
//
//  Created by 中央政治局常委 on 15/10/22.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <list>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode *fast = head->next->next, *slow = head->next;
        while (fast && slow) {
            if (fast == slow)
                return true;
            if (!fast->next || !fast->next->next) return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};
#endif /* solution_h */
