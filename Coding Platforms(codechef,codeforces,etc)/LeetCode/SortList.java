/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution 
{
    public ListNode merge(ListNode l1, ListNode l2)
    {
        ListNode l = new ListNode(0);
        ListNode head = l;
        while(l1 != null && l2 != null)
        {
            if(l1.val < l2.val)
            {
                l.next = l1;
                l = l.next;
                l1 = l1.next;
            }
            else
            {
                l.next = l2;
                l = l.next;
                l2 = l2.next;
            }
        }
        while(l1 != null)
        {
            l.next = l1;
            l = l.next;
            l1 = l1.next;
        }
        while(l2 != null)
        {
            l.next = l2;
            l = l.next;
            l2 = l2.next;
        }
        return head.next;
    }
    
    public ListNode sortList(ListNode head) 
    {
        if(head == null || head.next == null)
            return head;
        ListNode slow = head, fast = head, prev = null;
        while(fast != null && fast.next != null)
        {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }
        prev.next = null;
        head = sortList(head);
        slow = sortList(slow);
        return merge(head, slow);
    }
}
