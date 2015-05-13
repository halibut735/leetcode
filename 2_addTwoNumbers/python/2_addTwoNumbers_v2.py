# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def printList(l):
    tmp = l
    print tmp.val
    while(tmp.next):
        print tmp.next.val
        tmp = tmp.next

class Solution:
    # @param {ListNode} l1
    # @param {ListNode} l2
    # @return {ListNode}
    def addTwoNumbers(self, l1, l2):
        carryBit = 0
        retList = ListNode((l1.val + l2.val)%10)
        if l1.val + l2.val >= 10:
            carryBit = 1
        tmp = retList
        while(l1.next or l2.next):
            sumToList = 0
            if l1.next:
                sumToList += l1.next.val
                l1 = l1.next
            if l2.next:
                sumToList += l2.next.val
                l2 = l2.next
            sumToList += carryBit
            tmp.next = ListNode(sumToList % 10)
            if  sumToList >= 10:
                carryBit = 1
            else:
                carryBit = 0
            tmp = tmp.next

        if carryBit == 1:
            tmp.next = ListNode(1)

        return retList


def main():
    #defination of list1 and list2
    l1 = ListNode(9)
    l1.next = ListNode(7)
    l2 = ListNode(2)
    l2.next = ListNode(3)
    printList(l1)
    printList(l2)
    a = Solution()
    a.addTwoNumbers(l1, l2)
    printList(a.addTwoNumbers(l1, l2))

if __name__ == '__main__':
    main()
