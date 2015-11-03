//
//  solution.h
//  Insertion_Sort_List
//
//  Created by 中央政治局常委 on 15/10/31.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *pos = new ListNode(INT_MIN);
        pos->next = head;
        head = pos;
        
        for (auto it = head; it->next;) {
            if (it->next->val < it->val) {
                ListNode * tmp = it->next;
                it->next = tmp->next;
                for (auto pos = head; pos->next; pos = pos->next) {
                    if (pos->next->val >= tmp->val) {
                        ListNode * tmp2 = pos->next;
                        pos->next = tmp;
                        tmp->next = tmp2;
                        break;
                    }
                }
            }
            else {
                it = it->next;
            }
        }
        return head->next;
    }
};
#endif /* solution_h */
