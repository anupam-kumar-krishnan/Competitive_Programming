class Solution:
    def deleteMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp = head
        count = 0
        while (temp):
            temp = temp.next
            count +=1
        if count<=1:
            return None
        n = count
        mid = n//2
        temp = head
        while mid>1:
            temp = temp.next
            mid-=1
        temp.next = temp.next.next
        return head
