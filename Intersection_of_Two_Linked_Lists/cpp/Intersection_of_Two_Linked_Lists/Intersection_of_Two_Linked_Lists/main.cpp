//
//  main.cpp
//  Intersection_of_Two_Linked_Lists
//
//  Created by 中央政治局常委 on 15/12/15.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lena = 0, lenb = 0;
        ListNode *tmpa = headA, *tmpb = headB;
        for (tmpa = headA; tmpa; tmpa = tmpa->next)
            lena ++;
        for (tmpb = headB; tmpb; tmpb = tmpb->next)
            lenb ++;
        
        int diff = abs(lena - lenb);
        tmpa = headA;
        tmpb = headB;
        if (lena > lenb) {
            for (int i = 0; i < diff; ++ i)
                tmpa = tmpa->next;
        } else {
            for (int i = 0; i < diff; ++ i)
                tmpb = tmpb->next;
        }
        while (tmpa) {
            if (tmpa == tmpb) return tmpa;
            tmpa = tmpa->next;
            tmpb = tmpb->next;
        }
        return NULL;
    }
};

int main(int argc, const char * argv[]) {
    Solution test;
    ListNode * heada = new ListNode(0);
    ListNode * headb = NULL;
    test.getIntersectionNode(heada, headb);
    return 0;
}
