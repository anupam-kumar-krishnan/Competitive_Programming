// in c++ the linked list can be represented with a class and a Node class separately, which has two members, namely data and a next pointer which points to the next node.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node // node class
{
public:
    int data;
    node *next; // pointer

    node(int val) // constructor
    {
        data = val;
        next = NULL;
    }
};
void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);
    return 0;
}
