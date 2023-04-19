"""
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
"""

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

        # Attempt 1
        # l1.reverse()
        # l2.reverse()
        # ''.join(l1)
        # ''.join(l2)
        # sum = int(l1)+int(l2)
        # sum = [int(i) for i in str(sum)]
        # sum.reverse()
        # return sum

        # Attempt 2
        def addTwoNumCalc(moredigits, lessdigits):
            uprdgtlen = len(moredigits)
            lwrdgtlen = len(lessdigits)
            r = 0
            sum = []
            for i in range(lwrdgtlen):
                moredigits[uprdgtlen - i] + lessdigits[lwrdgtlen - i] + r
                sum.append(

        if len(l1) > len(l2):
            