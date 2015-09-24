//
//  solution2.h
//  Merge_k_Sorted_Lists
//
//  Created by 中央政治局常委 on 15/9/23.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution2_h
#define solution2_h

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

typedef ListNode* pListNode;
class cmp{
public:
    bool operator() (pListNode a, pListNode b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        head = NULL;
        priority_queue<pListNode, vector<pListNode>, cmp> heap;
        
        for (vector<ListNode*>::iterator it = lists.begin(); it < lists.end(); ++ it) {
            if ((*it)) {
                heap.push(*it);
            }
        }
        if (heap.empty())
            return NULL;
        tmp = heap.top();
        head = new ListNode(tmp->val);
        current_pos = head;
        tmp = tmp->next;
        heap.pop();
        if (tmp) {
            heap.push(tmp);
        }
        while (!heap.empty()) {
            tmp = heap.top();
            current_pos->next = new ListNode(tmp->val);
            current_pos = current_pos->next;
            tmp = tmp->next;
            heap.pop();
            if (tmp) {
                heap.push(tmp);
            }
        }
        return head;
    }
private:
    ListNode * tmp, * current_pos;
    ListNode * head;
};


#endif /* solution2_h */
