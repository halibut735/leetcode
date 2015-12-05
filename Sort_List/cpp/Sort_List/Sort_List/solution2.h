//
//  solution2.h
//  Sort_List
//
//  Created by 中央政治局常委 on 15/11/19.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution2_h
#define solution2_h
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <stack>
#include <fstream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return head;
        ListNode * slow = head, * fast = head, * llist = NULL, * rlist = NULL;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            if (!fast->next)
                fast = fast->next;
            else
                fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        llist = sortList(head);
        rlist = sortList(fast);
        return merge(llist, rlist);
    }
    
    ListNode * merge(ListNode * ll, ListNode * rr) {
        ListNode * ret = new ListNode(0), * tmp = ret;
        while (ll && rr) {
            if (ll->val < rr->val) {
                tmp->next = ll;
                ll = ll->next;
            } else {
                tmp->next = rr;
                rr = rr->next;
            }
            tmp = tmp->next;
            tmp->next = NULL;
        }
        tmp->next = ll ? ll : rr;
        tmp = ret;
        ret = ret->next;
        free(tmp);
        return ret;
    }
};
#endif /* solution2_h */





