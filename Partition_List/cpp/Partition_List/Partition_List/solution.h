//
//  solution.h
//  Partition_List
//
//  Created by 中央政治局常委 on 15/10/31.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <string>
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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode *pointer = head, *breakPoint = NULL, *preNode = NULL;
        /*
         *  这里可以直接开一个比x小的放在最前面，那样子第一个if就省略了~~~代码会少很多
         */
        if (head->val >= x) {
            breakPoint = head;
            while (breakPoint && breakPoint->val >= x) {
                preNode = breakPoint;
                breakPoint = breakPoint->next;
            }
            if (!breakPoint) return head;
            pointer = preNode;
            preNode->next = breakPoint->next;
            breakPoint->next = head;
            head = breakPoint;
        }
        else {
            while (pointer && pointer->val < x) {
                breakPoint = pointer;
                pointer = pointer->next;
            }
            if (!pointer) return head;
        }
        
        while (pointer->next) {
            if (pointer->next->val < x) {
                ListNode * tmp = breakPoint->next;
                breakPoint->next = pointer->next;
                breakPoint = breakPoint->next;
                pointer->next = breakPoint->next;
                breakPoint->next = tmp;
            }
            else {
                pointer = pointer->next;
            }
        }
        return head;
    }
};
#endif /* solution_h */
