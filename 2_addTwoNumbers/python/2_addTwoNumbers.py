# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def printList(l):
    tmp = l
    print tmp.val
    while(tmp.next):
        print tmp.next
        tmp = tmp.next

class Solution:
    # @param {ListNode} l1
    # @param {ListNode} l2
    # @return {ListNode}
    def list2Number(self, listnode):
        a = listnode.val
        power = 10
        while(listnode.next != None):
            a = a + listnode.next.val * power
            power *= 10
            listnode = listnode.next
        return a

    def number2List(self, num):
        ret = ListNode(num % 10)
        tmp = ret
        num /= 10
        while(num):
            tmp.next = ListNode(num % 10)
            tmp = tmp.next
            num /= 10
        return ret

    def addTwoNumbers(self, l1, l2):
        num1 = self.list2Number(l1)
        print 'num1 equals ' , num1
        num2 = self.list2Number(l2)
        print 'num2 equals ' , num2
        sum = num1 + num2
        print 'sum equals ' , sum
        return self.number2List(sum)



def main():
    l1 = ListNode(9)
    l1.next = ListNode(7)
    l2 = ListNode(2)
    l2.next = ListNode(3)
    a = Solution()
    a.addTwoNumbers(l1, l2)
    printList(a)

if __name__ == '__main__':
    main()
