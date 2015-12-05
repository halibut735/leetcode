//
//  solution.h
//  Sort_List
//
//  Created by 中央政治局常委 on 15/11/19.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#ifndef solution_h
#define solution_h
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
        ListNode * tmp = head;
        vector<int> vec;
        while (tmp) {
            vec.push_back(tmp->val);
            tmp = tmp->next;
        }
        sort(vec.begin(), vec.end());
        tmp = head;
        for (auto each:vec) {
            tmp->next = new ListNode(each);
            tmp = tmp->next;
        }
        head = head->next;
        return head;
    }
};
#endif /* solution_h */
