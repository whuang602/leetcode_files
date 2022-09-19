# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        value=l1.val+l2.val
        overfill=value/10
        l3 = ListNode(val=value%10,next=None)
        l3Tracker = l3
        l1=l1.next
        l2=l2.next
        while(l1!=None or l2!=None):
            if (l1!=None and l2!=None):
                value = l1.val + l2.val
                l1=l1.next
                l2=l2.next
            elif (l2==None):
                value = l1.val
                l1=l1.next
            else:
                value = l2.val
                l2=l2.next
                
            l3Tracker.next =ListNode(val=(value+overfill)%10,next=None)
            overfill=(value+overfill)/10
            l3Tracker=l3Tracker.next
            
        if (overfill>0):
            l3Tracker.next = ListNode(val=overfill,next=None)
            
        return l3
            
            
        