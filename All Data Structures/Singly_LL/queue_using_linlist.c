#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node* front=NULL;
struct node* rear=NULL;

void add(int x)
{
  struct node* temp;

  temp=(struct node *)malloc(sizeof(struct node));

  if(temp==NULL)
    printf("Queue OVERFLOW");

  else
  {
    temp->data=x;
    front =temp;
    rear=temp;

  }
}


