#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create(int A[], int n)
{
    struct node *new, *last;
    head = (struct node *)malloc(sizeof(struct node));

    head->data = A[0];
    head->next = head; // head will point to itself
    last = head;

    for (int i = 1; i < n; i++)
    {
        new = (struct node *)malloc(sizeof(struct node));

        new->data = A[i];
        new->next = last->next; // we have to point new where last was pointing  (more like inserting a node b/w two nodes)
        last->next = new;
        last = new;
    }
}

void Display(struct node *p)
{
    do
    {                           // we have to stop when p goes to head 2nd time
        printf("%d ", p->data); // if we use while loop, it wont run coz p is assigned to head which fails the condition
        p = p->next;
    } while (p != head);
    printf("\n");
}

struct node *insertAtBeg(struct node *p)
{

    struct node *new;
    p = head;
    while (p->next != head) // we'll have to traverse till last node so that we can point it to new node
    {
        p = p->next;
    }
    new = (struct node *)malloc(sizeof(struct node));
    printf("Enter new node data to be inserted at beginning : ");
    scanf("%d", &new->data);

    new->next = head; // linking new node with head

    p->next = new; // making last node pointing to newly created first node

    head = new; // making new node as head;

    return head;
}

void insertAtPosition(struct node *p, int pos)
{
    if (pos == 0) // same as above
    {
        struct node *new;
        p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter new node data : ");
        scanf("%d", &new->data);

        new->next = head;

        p->next = new;

        head = new;
    }
    else
    {
        struct node *new = (struct node *)malloc(sizeof(struct node));

        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        printf("Enter new node data : ");
        scanf("%d", &new->data);
        new->next = p->next;
        p->next = new;
    }
}

int Delete(struct node *p, int pos)
{
    int x = -1;
    struct node *q = NULL;
    p = head;
    if (pos <= 0)
    {
        printf("Invalid Position!\n");
    }
    else if (pos == 1) // deleting head node
    {
        while (p->next != head)
        {
            p = p->next; // p became last node
        }
        p->next = head->next; // assigning p->next = head->next
        x = head->data;       // taking the value
        free(head);
        head = p->next; // assigning head as p->next (which was head ->next)
    }
    else
    {

        for (int i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }

        q->next = p->next;
        x = p->data;
        free(p);
    }

    return x;
}

int main()
{

    int A[] = {10, 20, 30, 40, 50};

    create(A, 5);

    Display(head);

    insertAtBeg(head);

    Display(head);
    int pos;
    printf("Enter position after which you want to insert a node : ");
    scanf("%d", &pos);

    insertAtPosition(head, pos);

    Display(head);

    int del;
    printf("Enter node position you want to delete : ");
    scanf("%d", &del);

    printf("Deleted value is %d\n", Delete(head, del));

    Display(head);

    return 0;
}