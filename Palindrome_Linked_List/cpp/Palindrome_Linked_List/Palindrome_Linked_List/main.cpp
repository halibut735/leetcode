//
//  main.cpp
//  Palindrome_Linked_List
//
//  Created by 中央政治局常委 on 15/12/16.
//  Copyright © 2015年 中央政治局常委. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode *fast = head->next, *slow = head, * tmp = NULL;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        while (fast && fast->next) {
            tmp = fast->next;
            fast->next = fast->next->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        fast = slow->next;
        slow = head;
        while (fast) {
            if (fast->val != slow->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};


fstream input("/Users/bingoboy/Desktop/in.txt");
int main(int argc, const char * argv[]) {
    Solution test;
    ListNode * head = new ListNode(0), *tmp = head;
    int num;
    while (input >> num) {
        tmp->next = new ListNode(num);
        tmp = tmp->next;
    }
    cout << test.isPalindrome(head) << endl;
    return 0;
}
