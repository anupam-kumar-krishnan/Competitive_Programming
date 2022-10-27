// C++ program to sort a stack using recursion
#include <iostream>
using namespace std;

struct stack {
	int data;
	struct stack* next;
};

//  initialize stack
void initStack(struct stack** s) { *s = NULL; }

//  check if stack is empty
int isEmpty(struct stack* s)
{
	if (s == NULL)
		return 1;
	return 0;
}

//  push an item to stack
void push(struct stack** s, int x)
{
	struct stack* p = (struct stack*)malloc(sizeof(*p));

	if (p == NULL) {
		printf(stderr, "Memory allocation failed.\n");
		return;
	}

	p->data = x;
	p->next = *s;
	*s = p;
}

// remove an item from stack
int pop(struct stack** s)
{
	int x;
	struct stack* temp;

	x = (*s)->data;
	temp = *s;
	(*s) = (*s)->next;
	free(temp);

	return x;
}

// find top item
int top(struct stack* s) { return (s->data); }

void sortedInsert(struct stack** s, int x)
{
	if (isEmpty(*s) or x > top(*s)) {
		push(s, x);
		return;
	}
	int temp = pop(s);
	sortedInsert(s, x);
	push(s, temp);
}

// to sort stack
void sortStack(struct stack** s)
{
	if (!isEmpty(*s)) {
		
		int x = pop(s);
		sortStack(s);
		sortedInsert(s, x);
	}
}

//  to print contents of stack
void printStack(struct stack* s)
{
	while (s) {
		cout << s->data << " ";
		s = s->next;
	}
	cout << "\n";
}

int main()
{
	struct stack* top;

	initStack(&top);
	push(&top, 30);
	push(&top, -5);
	push(&top, 18);
	push(&top, 14);
	push(&top, -3);

	cout << "Stack elements before sorting:\n";
	printStack(top);

	sortStack(&top);
	cout << "\n";

	cout << "Stack elements after sorting:\n";
	printStack(top);

	return 0;
}
