//Implementation of stack
#include<stdio.h>
#define MAX 10
struct stack
{
	int item [MAX];
	int top;
};
struct stack s;
void push (struct stack *s, int num)
{
	if(s->top==MAX -1)
	{
		printf("\n stack overflow");
	}
	else{

	s->top=s->top+1;
	s->item[s->top]=num;
		}
	}

void pop (struct stack *s)
{
	int dt;
	if(s->top==-1)
	{
		printf("\n stack underflow");
	}
	else
	{
		dt=s->item[s->top];
		s->top=s->top-1;
		printf("\n poped item=%d", dt);
	}
}
void display (struct stack *s)
{
	int i;
	if(s->top==-1)
	{
		printf("\n stack is empty");
	}
	else{
		printf("\n stack content \n ");
	}
	for (i=s->top; i>=0;i--)
	{
		printf("%d\n",s->item[i]);
	}
}
int main()
{
	int num, choice;
	s.top=-1;
	printf("1.push\n 2.pop\n 3.display\n  4.exit");
	while(1)
	{
		printf("\n Enter your choice");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n Enter the no. you want to push:");
				scanf("%d", &num);
				push(&s, num);
				break;
			case 2:
				pop(&s);
				break;
			case 3:
				display (&s);
				break;
			case 4:
				exit(1);	
		}
}
	return 0;
}