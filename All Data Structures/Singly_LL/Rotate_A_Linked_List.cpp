// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        if(head==NULL || head->next==NULL)return head;
        Node* temp = head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        if(count==k)return head;
        temp = head;
        Node* prev = head;
        Node* mid = head;
        Node* h = head;
        while(temp->next!=NULL){
            if(k>=0){
                prev=mid;
                mid = temp;
                --k;
            }
            temp = temp->next;
        }
        if(k>=0){
            prev = mid;
            mid=mid->next;
        }
        prev->next = NULL;
        head = mid;
        temp->next = h;
        return head;
    }
};
    


// { Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}
  // } Driver Code Ends