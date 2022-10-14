#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
}*top=NULL;

void push(int x)
{
   struct node *temp;

   temp = (struct node*) malloc(sizeof(struct node));

   if(temp==NULL)
   {
    printf("Stack Overflow");
   }

   else
   {
    temp->data= x;
    temp->next= top;
    top=temp;
   }

}

void pop()
{

  struct node *temp2;

  temp2=top;

  if(temp2==NULL)
  {
    printf("STACK UNDERFLOW");
  }

  else{
  top=top->next;

  free(temp2);
  }

}

void display(struct node *p)
{
  while(p)
  {
    printf("%d ", p->data);
    p=p->next;
  }
  printf("\n");
}

int main()
{
  printf("Enter the number of elements to be inserted in the stack\n");

  int n;
  scanf("%d", &n);

  printf("\nEnter the elements of stack:\n");

  for(int i=0;i<n;i++)
  {
    int x;
    scanf("%d", &x);

    push(x);
  }

  display(top);

  printf("Enter 1 if you want to pop an element");

  int xy;
  scanf("%d", &xy);

  if(xy==1)
  {
    pop();

    display(top);
  }
}



