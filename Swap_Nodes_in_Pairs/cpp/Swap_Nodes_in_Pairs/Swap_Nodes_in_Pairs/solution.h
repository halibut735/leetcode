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
        if (head == NULL || head->next == NULL) return head;
        int tmp;
        ListNode * preNode = head, *nextNode = head->next;
        
        while (1) {
            tmp = preNode->val;
            preNode->val = nextNode->val;
            nextNode->val = tmp;
            if (nextNode->next)
                preNode = nextNode->next;
            else
                return head;
            if (preNode->next)
                nextNode = preNode->next;
            else return head;
        }
        
        return head;
    }
};
#endif /* solution_h */
