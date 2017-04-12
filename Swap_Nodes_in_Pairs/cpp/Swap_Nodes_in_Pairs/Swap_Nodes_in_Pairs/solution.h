//
//  solution.h
//  Swap_Nodes_in_Pairs
//
//  Created by 中央政治局常委 on 15/10/25.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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
    ListNode* swapPairs(ListNode* head) {
        ListNode redun(0);
        redun.next = head;
        head = &redun;
        while (head->next && head->next->next) {
            ListNode * tmp = head->next;
            head->next = tmp->next;
            tmp->next = head->next->next;
            head = head->next->next = tmp;
        }
        return redun.next;
    }
};
#endif /* solution_h */
