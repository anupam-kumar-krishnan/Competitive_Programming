/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
        if(head==NULL || head->next==NULL) return head;
        
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *odd_head = head;
        ListNode *even_head = head->next;
        
        while(even!=NULL && even->next!=NULL)
        {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
            
        }
        odd->next = even_head;
        return head;      
        
    }
};