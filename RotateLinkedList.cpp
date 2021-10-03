/*
To rotate a linked list by k, we can first make the linked list circular and then moving
 k-1 steps forward from head node, making (k-1)th node’s next to null and make kth node as head.
*/

// C++ program to rotate
// a linked list counter clock wise

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
public:
	int data;
	Node *next;
};

// This function rotates a linked list
// counter-clockwise and updates the
// head. The function assumes that k is
// smaller than size of linked list.
void rotate(Node **head_ref, int k)
{
	if (k == 0)
		return;

	// Let us understand the below
	// code for example k = 4 and
	// list = 10->20->30->40->50->60.
	Node *current = *head_ref;

	// Traverse till the end.
	while (current->next != NULL)
		current = current->next;

	current->next = *head_ref;
	current = *head_ref;

	// traverse the linked list to k-1 position which
	// will be last element for rotated array.
	for (int i = 0; i < k - 1; i++)
		current = current->next;

	// update the head_ref and last element pointer to NULL
	*head_ref = current->next;
	current->next = NULL;
}

/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(Node **head_ref, int new_data)
{
	/* allocate node */
	Node *new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print linked list */
void printList(Node *node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

/* Driver code*/
int main(void)
{
	/* Start with the empty list */
	Node *head = NULL;

	// create a list 10->20->30->40->50->60
	for (int i = 60; i > 0; i -= 10)
		push(&head, i);

	cout << "Given linked list \n";
	printList(head);
	rotate(&head, 4);

	cout << "\nRotated Linked list \n";
	printList(head);

	return (0);
}
