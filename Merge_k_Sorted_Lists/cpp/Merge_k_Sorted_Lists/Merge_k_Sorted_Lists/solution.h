//
//  solution.h
//  Merge_k_Sorted_Lists
//
//  Created by 中央政治局常委 on 15/9/22.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h

#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool cmp(const ListNode * a, const ListNode * b){
    return a->val > b->val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        head = NULL;
        vector<ListNode*> min_heap;
        min_heap.reserve(lists.size());
        for (vector<ListNode*>::iterator it = lists.begin(); it < lists.end(); ++ it) {
            if ((*it)) {
                min_heap.push_back(*it);
            }
        }
        if (!min_heap.size()) {
            return head;
        }
        make_heap(min_heap.begin(), min_heap.end(), cmp);
        head = new ListNode((min_heap.front())->val);
        current_pos = head;
        pop_heap(min_heap.begin(), min_heap.end(), cmp);
        min_heap.pop_back();
        while (min_heap.size()) {
            tmp = min_heap.front();
            current_pos->next = new ListNode(tmp->val);
            current_pos = current_pos->next;
            tmp = tmp->next;
            pop_heap(min_heap.begin(), min_heap.end(), cmp);
            min_heap.pop_back();
            if (tmp) {
                min_heap.push_back(tmp);
                push_heap(min_heap.begin(), min_heap.end(), cmp);
            }
        }
        return head;
    }
    ListNode * tmp, * current_pos;
    ListNode * head;
};

#endif /* solution_h */
