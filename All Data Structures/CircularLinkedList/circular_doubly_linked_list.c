#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *first = NULL, *last = NULL;

void create(int A[], int n)
{
    struct node *p;
    first = (struct node *)malloc(sizeof(struct node));
    first->data = A[0];
    first->next = first;
    first->prev = first;
    last = first;

    for (int i = 1; i < n; i++)
    {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = A[i];

        p->next = first;
        first->prev = p;
        p->prev = last;
        last->next = p;
        last = p;
    }
}

void Display(struct node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != first);
    printf("\n");
}

int count(struct node *p)
{
    int num = 0;
    do
    {
        num++;
        p = p->next;
    } while (p != first);
    return num;
}

void insert(struct node *p, int pos)
{
    p = first;
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (pos < 0 || pos > count(p))
    {
        printf("Invalid Index\n");
    }
    else if (pos == 0)
    {
        printf("Enter first node data : ");
        scanf("%d", &new->data);
        new->next = first;
        first->prev = new;

        new->prev = last;
        last->next = new;
        first = new;
    }
    else if (pos == count(p))
    {
        printf("Enter last node data : ");
        scanf("%d", &new->data);
        new->next = first;
        first->prev = new;
        last->next = new; // last global variable is not needed. It can be
        new->prev = last; // easily obtained by last = first->prev
        last = new;
    }
    else
    {
        printf("Enter new node data : ");
        scanf("%d", &new->data);
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }

        new->next = p->next;
        (p->next)->prev = new;
        p->next = new;
        new->prev = p;
    }
}

int Delete(struct node *p, int pos)
{
    p = first;
    struct node *temp;
    int x = -1;
    if (pos <= 0 || pos > count(p))
    {
        printf("Invalid Index\n");
    }
    else if (pos == 1)
    {
        temp = p;
        p = p->next;

        last->next = p;
        p->prev = last;
        x = temp->data;
        first = p;
        free(temp);
    }
    else if (pos == count(p))
    {
        temp = last;
        first->prev = last->prev;
        last->prev->next = first;
        x = temp->data;
        last = last->prev;
        free(temp);
    }

    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        struct node *q = p->prev;

        q->next = p->next;
        p->next->prev = q;
        x = p->data;
        free(p);
    }

    return x;
}

int main()
{

    int A[] = {10, 20, 30, 40, 50};

    create(A, 5);
    Display(first);
    int pos1, pos2;

    printf("Enter node position after which you wanna insert : ");
    scanf("%d", &pos1);

    insert(first, pos1);
    Display(first);

    printf("Enter node position which you wanna delete : ");
    scanf("%d", &pos2);

    printf("Deleted element is %d\n", Delete(first, pos2));

    Display(first);

    return 0;
}