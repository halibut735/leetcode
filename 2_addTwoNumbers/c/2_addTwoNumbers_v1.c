/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode * retList = (struct ListNode* ) malloc(sizeof(struct ListNode));
    int sumToAdd = l1->val + l2->val;
    struct ListNode * tmp = retList;
    int carryBit = sumToAdd>=10?1:0;
    tmp->val = sumToAdd % 10;
    while(l1->next || l2->next){
        sumToAdd = 0;
        if(l1->next){
            sumToAdd += l1->next->val;
            l1 = l1->next;
        }
        if(l2->next){
            sumToAdd += l2->next->val;
            l2 = l2->next;
        }
        sumToAdd += carryBit;
        tmp->next = (struct ListNode* ) malloc(sizeof(struct ListNode));
        tmp = tmp->next;
        tmp->val = sumToAdd % 10;
        printf("%d", tmp->val);
        tmp->next = NULL;
        carryBit = sumToAdd>=10?1:0;
    }
    if(carryBit){
        tmp->next = (struct ListNode* ) malloc(sizeof(struct ListNode));
        tmp = tmp->next;
        tmp->val = 1;
        tmp->next = NULL;
    }
    return retList;
}
int main(){
    struct ListNode *l1 =(struct ListNode* ) malloc(sizeof(struct ListNode));
    l1->val = 1;
    l1->next = (struct ListNode* ) malloc(sizeof(struct ListNode));
    l1->next->val = 6;
    l1->next->next = (struct ListNode* ) malloc(sizeof(struct ListNode));
    l1->next->next->val = 7;
    l1->next->next->next = NULL;
    struct ListNode *l2 =(struct ListNode* ) malloc(sizeof(struct ListNode));
    l2->val = 8;
    l2->next = (struct ListNode* ) malloc(sizeof(struct ListNode));
    l2->next->val = 9;
    l2->next->next = (struct ListNode* ) malloc(sizeof(struct ListNode));
    l2->next->next->val = 2;
    l2->next->next->next = NULL;
    addTwoNumbers(l1, l2);
}
