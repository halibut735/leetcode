#include <iostream>
#include "solution.h"

using namespace std;

int main()
{
    ListNode *head;
    ListNode aa(1);
    head = &aa;

    Solution sol;
    sol.rotateRight(head, 1);
    sol.print_list(head);
    return 1;
}
