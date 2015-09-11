#include <iostream>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *front, *tail;
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return head;
        front = tail = head;
        for(int i = 0; i < k; ++ i)
            front = front->next;
        while(front->next){
            front = front->next;
            tail = tail->next;
        }
        front->next = head;
        head = tail->next;
        tail->next = NULL;
        return head;
    }
    void print_list(ListNode * head){
        ListNode * tmp = head;
        while(tmp){
            cout << tmp->val;
            tmp = tmp->next;
        }
    }
};
