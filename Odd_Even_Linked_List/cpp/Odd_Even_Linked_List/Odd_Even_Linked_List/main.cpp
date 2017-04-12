//
//  main.cpp
//  Odd_Even_Linked_List
//
//  Created by 中央政治局常委 on 16/1/18.
//  Copyright © 2016年 中央政治局常委. All rights reserved.
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        pListNode oddT = head, evenT = head->next, oddNode = NULL;
        while (evenT && (oddNode = evenT->next)) {
            evenT = evenT->next = oddNode->next;
            oddNode->next = oddT->next;
            oddT = oddT->next = oddNode;
        }
        return head;
    }
private:
    typedef ListNode * pListNode;
};

int main(int argc, const char * argv[]) {
    cout << (7 & -7) << endl;
    return 0;
}
