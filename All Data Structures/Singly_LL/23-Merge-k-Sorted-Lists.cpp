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
class Solution
{
public:
    ListNode *merge(ListNode *left, ListNode *right)
    {
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        while (left && right)
        {
            if (left->val < right->val)
            {
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else
            {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        if (left != NULL)
        {
            temp->next = left;
            temp = left;
        }
        if (right != NULL)
        {
            temp->next = right;
            temp = right;
        }
        return dummy->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
        ListNode *head = lists[0];
        for (int i = 1; i < lists.size(); i++)
        {
            head = merge(lists[i], head);
        }
        return head;
    }
};